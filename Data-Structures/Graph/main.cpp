#include "./adj_list.hpp"
#include "./adj_matrix.hpp"

int main()
{
  Graph_list g(6, false);  // Change to `true` for a directed graph
  std::cout << "\nAdjacency List:\n";
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

  Graph_mat g_mat(6, false);  // Change to `true` for a directed graph

  g_mat.add_edge(0, 1);
  g_mat.add_edge(0, 2);
  g_mat.add_edge(1, 3);
  g_mat.add_edge(2, 4);
  g_mat.add_edge(4, 5);

  std::cout << "\nAdjacency Matrix:\n";
  g_mat.print_graph();

  std::cout << "\nDFS Traversal: ";
  for (int v : g_mat.dfs(0)) std::cout << v << " ";
  std::cout << "\n";

  std::cout << "BFS Traversal: ";
  for (int v : g_mat.bfs(0)) std::cout << v << " ";
  std::cout << "\n";

  if (g_mat.is_connected())
    std::cout << "The graph is connected.\n";
  else
    std::cout << "The graph is not connected.\n";

  return (0);
}
