#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

const int INF = INT_MAX;

int tsp(const std::vector<std::vector<int>> &dist)
{
  int n = dist.size();  // Number of cities

  // DP table: dp[subset][last_city] -> Minimum cost to visit all cities in 'subset' ending at 'last_city'
  std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, INF));

  // Base case: Starting at city 0
  dp[1][0] = 0;

  // Iterate through all subsets of cities
  for (int mask = 1; mask < (1 << n); ++mask)
  {
    for (int u = 0; u < n; ++u)
    {
      if (!(mask & (1 << u)))
        continue;  // Skip if 'u' is not in the current subset
      for (int v = 0; v < n; ++v)
      {
        if (mask & (1 << v) || dist[u][v] == INF)
          continue;  // Skip if 'v' is already visited or no direct path
        dp[mask | (1 << v)][v] = std::min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
      }
    }
  }

  // Find the minimum cost to visit all cities and return to the start
  int min_cost = INF;
  for (int u = 1; u < n; ++u)
    if (dist[u][0] != INF)
      min_cost = std::min(min_cost, dp[(1 << n) - 1][u] + dist[u][0]);

  return min_cost;
}

int main()
{
  // Adjacency matrix of distances
  std::vector<std::vector<int>> dist = {
      {0, 10, 15, 20},
      {10, 0, 35, 25},
      {15, 35, 0, 30},
      {20, 25, 30, 0},
  };

  int result = tsp(dist);

  if (result == INF)
    std::cout << "No valid TSP tour exists.\n";
  else
    std::cout << "The cost of the most efficient tour = " << result << '\n';

  return 0;
}
