#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> adj_matrix;

class Graph_mat
{
private:
  adj_matrix _adj_matrix;  // Adjacency matrix
  int _V;                  // Number of vertices
  bool _is_directed;       // Flag for directed/undirected graph

public:
  // Constructors
  Graph_mat(int V, bool is_directed = false) : _V(V), _is_directed(is_directed), _adj_matrix(V, std::vector<int>(V, 0)) {}

  Graph_mat(int V, bool is_directed, const adj_matrix &matrix) : _V(V), _is_directed(is_directed), _adj_matrix(matrix) {}

  ~Graph_mat() {}

  // Add an edge
  void add_edge(int u, int v)
  {
    _adj_matrix[u][v] = 1;
    if (!_is_directed)
      _adj_matrix[v][u] = 1;
  }

  // Delete an edge
  void delete_edge(int u, int v)
  {
    _adj_matrix[u][v] = 0;
    if (!_is_directed)
      _adj_matrix[v][u] = 0;
  }

  // Print the graph as an adjacency matrix
  void print_graph() const
  {
    for (const auto &row : _adj_matrix)
    {
      for (int val : row) std::cout << val << " ";
      std::cout << "\n";
    }
  }

  // Perform DFS and return the traversal
  std::vector<int> dfs(int start)
  {
    std::vector<bool> visited(_V, false);
    std::vector<int> traversal;
    dfs_util(start, visited, traversal);
    return traversal;
  }

  // Perform BFS and return the traversal
  std::vector<int> bfs(int start)
  {
    std::vector<bool> visited(_V, false);
    std::vector<int> traversal;
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      traversal.push_back(u);

      for (int v = 0; v < _V; ++v)
      {
        if (_adj_matrix[u][v] && !visited[v])
        {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    return traversal;
  }

  // Check if the graph is connected
  bool is_connected()
  {
    std::vector<int> traversal = dfs(0);
    return traversal.size() == _V;
  }

private:
  void dfs_util(int u, std::vector<bool> &visited, std::vector<int> &traversal)
  {
    visited[u] = true;
    traversal.push_back(u);

    for (int v = 0; v < _V; ++v)
      if (_adj_matrix[u][v] && !visited[v])
        dfs_util(v, visited, traversal);
  }
};
