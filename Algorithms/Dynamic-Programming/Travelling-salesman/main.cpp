#include <climits>
#include <iostream>
#include <vector>

const int INF = INT_MAX;

// Function to solve TSP
int tsp(int current, std::vector<bool> &visited, const std::vector<std::vector<int>> &dist, int count, int n, int start)
{
  // Base case: All cities visited, return cost to go back to the starting city
  if (count == n)
    return dist[current][start];

  int result = INF;

  // Explore unvisited cities
  for (int next = 0; next < n; ++next)
  {
    if (!visited[next])
    {
      visited[next] = true;  // Mark as visited
      int cost = dist[current][next] + tsp(next, visited, dist, count + 1, n, start);
      result = std::min(result, cost);
      visited[next] = false;  // Backtrack
    }
  }

  return result;
}

int main()
{
  // Example graph: Distance matrix
  std::vector<std::vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

  int n = dist.size();  // Number of cities
  std::vector<bool> visited(n, false);
  visited[0] = true;  // Start from city 0

  int result = tsp(0, visited, dist, 1, n, 0);
  std::cout << "The cost of the most efficient tour is " << result << std::endl;

  return 0;
}
