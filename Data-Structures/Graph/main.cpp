#include <vector>

typedef std::vector<std::vector<int>> Edge_data;

class Graph
{
  Edge_data edges;

public:
  Graph() {}
  Graph(const Edge_data &edges) : edges(edges) {}
  Graph(size_t n) : edges(n) {}


};

int main()
{
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};

  Graph g;
  return 0;
}
