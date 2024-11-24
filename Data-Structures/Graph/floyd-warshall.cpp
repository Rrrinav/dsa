#include <iostream>
#include <limits>
#include <vector>

const int INF = std::numeric_limits<int>::max();
typedef std::vector<std::vector<int>> graph;

void floydWarshall(const std::vector<std::vector<int>> &graph)
{
  int V = graph.size();
  std::vector<std::vector<int>> dist = graph;

  for (int k = 0; k < V; ++k)
  {
    for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j < V; ++j)

        if (dist[i][k] != INF && dist[k][j] != INF)
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  std::cout << "Shortest distances between all pairs of vertices:\n";
  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
      if (dist[i][j] == INF)
        std::cout << "INF ";
      else
        std::cout << dist[i][j] << " ";
    std::cout << std::endl;
  }
}

int main()
{
  graph graph = {{0, 3, INF, 7},  //
                 {8, 0, 2, INF},  //
                 {5, INF, 0, 1},  //
                 {2, INF, INF, 0}};

  floydWarshall(graph);

  return 0;
}
