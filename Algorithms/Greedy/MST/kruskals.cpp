#include <algorithm>
#include <iostream>
#include <vector>

struct Edge
{
  int u, v, weight;
  bool operator<(const Edge &other) const { return weight < other.weight; }
};

class UnionFind
{
private:
  std::vector<int> parent, rank;

public:
  UnionFind(int n) : parent(n), rank(n, 0)
  {
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int find(int u)
  {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  }

  void unite(int u, int v)
  {
    int rootU = find(u), rootV = find(v);
    if (rootU != rootV)
    {
      if (rank[rootU] > rank[rootV])
      {
        parent[rootV] = rootU;
      }
      else if (rank[rootU] < rank[rootV])
      {
        parent[rootU] = rootV;
      }
      else
      {
        parent[rootV] = rootU;
        rank[rootU]++;
      }
    }
  }
};

int kruskalMST(int V, const std::vector<Edge> &edges)
{
  std::vector<Edge> sortedEdges = edges;
  std::sort(sortedEdges.begin(), sortedEdges.end());

  UnionFind uf(V);
  int mstWeight = 0;

  for (const auto &edge : sortedEdges)
  {
    if (uf.find(edge.u) != uf.find(edge.v))
    {
      uf.unite(edge.u, edge.v);
      mstWeight += edge.weight;
      std::cout << "Edge (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << " added.\n";
    }
  }

  return mstWeight;
}

int main()
{
  int V = 4;
  std::vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

  int mstWeight = kruskalMST(V, edges);
  std::cout << "Total weight of MST is " << mstWeight << std::endl;
  return 0;
}
