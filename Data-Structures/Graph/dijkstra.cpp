#include <iostream>
#include <limits>
#include <queue>
#include <vector>

typedef std::vector<std::vector<std::pair<int, int>>> adj_list;

std::vector<int> dijkstra(const adj_list &adj_list, int start)
{
  size_t n = adj_list.size();
  std::vector<int> dist(n, std::numeric_limits<int>::max());
  dist[start] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
  pq.push({0, start});

  while (!pq.empty())
  {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (d > dist[u])
      continue;

    for (const auto &neighbor : adj_list[u])
    {
      int v = neighbor.first;
      int weight = neighbor.second;

      if (dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}

int main()
{
  int vertices = 5, edges;
  adj_list adj_list(vertices);

  adj_list[0].push_back({1, 2});
  adj_list[0].push_back({2, 4});
  adj_list[1].push_back({3, 1});
  adj_list[2].push_back({3, 3});
  adj_list[2].push_back({4, 5});
  adj_list[4].push_back({5, 2});

  std::vector<int> distances = dijkstra(adj_list, 0);

  std::cout << "Shortest distances from vertex " << 0 << ":" << std::endl;
  for (int i = 0; i < vertices; ++i)
    if (distances[i] == std::numeric_limits<int>::max())
      std::cout << i << ": INF" << std::endl;
    else
      std::cout << i << ": " << distances[i] << std::endl;

  return 0;
}
