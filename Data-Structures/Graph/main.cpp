#include "./adj_list.hpp"

int main()
{
  Graph g(6, false);  // Change to `true` for a directed graph

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(4, 5);

  g.print_graph();

  auto dfs_result = g.dfs(0);
  std::cout << "DFS Traversal: ";
  for (int node : dfs_result) std::cout << node << " ";
  std::cout << std::endl;

  auto bfs_result = g.bfs(0);
  std::cout << "BFS Traversal: ";
  for (int node : bfs_result) std::cout << node << " ";
  std::cout << std::endl;

  if (g.is_connected())
    std::cout << "The graph is connected." << std::endl;
  else
    std::cout << "The graph is not connected." << std::endl;

  return 0;
}
