#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Graph
{
private:
  std::vector<std::vector<int>> _adj_list;  // Adjacency list
  bool _is_directed;                        // Flag for directed/undirected graph

public:
  Graph(size_t vertices, bool isDirected = false) : _adj_list(vertices), _is_directed(isDirected) {}

  void add_edge(int u, int v)
  {
    _adj_list[u].push_back(v);
    if (!_is_directed)
      _adj_list[v].push_back(u);  // Add reverse edge for undirected graph
  }

  void delete_edge(int u, int v)
  {
    auto it = std::find(_adj_list[u].begin(), _adj_list[u].end(), v);
    if (it != _adj_list[u].end())
      _adj_list[u].erase(it);

    if (!_is_directed)
    {
      auto it2 = std::find(_adj_list[v].begin(), _adj_list[v].end(), u);
      if (it2 != _adj_list[v].end())
        _adj_list[v].erase(it2);
    }
  }

  void print_graph() const
  {
    for (size_t i = 0; i < _adj_list.size(); ++i)
    {
      std::cout << i << ": ";
      for (int v : _adj_list[i]) std::cout << v << " ";
      std::cout << std::endl;
    }
  }

  std::vector<int> dfs(int start)
  {
    std::vector<bool> visited(_adj_list.size(), false);
    std::vector<int> traversal;
    dfs_util(start, visited, traversal);
    return traversal;
  }

  std::vector<int> bfs(int start)
  {
    std::vector<bool> visited(_adj_list.size(), false);
    std::vector<int> traversal;
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      traversal.push_back(u);

      for (int v : _adj_list[u])
      {
        if (!visited[v])
        {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    return traversal;
  }

  bool is_connected() const
  {
    std::vector<bool> visited(_adj_list.size(), false);
    std::vector<int> traversal;
    dfs_util(0, visited, traversal);

    for (bool v : visited)
      if (!v)
        return false;
    return true;
  }

private:
  void dfs_util(int u, std::vector<bool> &visited, std::vector<int> &traversal) const
  {
    visited[u] = true;
    traversal.push_back(u);

    for (int v : _adj_list[u])
      if (!visited[v])
        dfs_util(v, visited, traversal);
  }
};
