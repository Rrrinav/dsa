#include <iostream>
#include <queue>
#include <vector>

struct Edge
{
  int vertex, weight;
  bool operator>(const Edge &other) const { return weight > other.weight; }
};

int primMST(int V, const std::vector<std::vector<Edge>> &adjList)
{
  std::vector<bool> inMST(V, false);
  std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
  pq.push({0, 0});  // Start with vertex 0 and weight 0

  int mstWeight = 0;

  while (!pq.empty())
  {
    Edge edge = pq.top();
    pq.pop();

    int u = edge.vertex;

    if (inMST[u])
      continue;
    inMST[u] = true;
    mstWeight += edge.weight;

    std::cout << "Vertex " << u << " added to MST with edge weight " << edge.weight << "\n";

    for (const auto &neighbor : adjList[u])
      if (!inMST[neighbor.vertex])
        pq.push(neighbor);
  }

  return mstWeight;
}

int main()
{
  int V = 4;
  std::vector<std::vector<Edge>> adjList(V);

  adjList[0] = {{1, 10}, {2, 6}, {3, 5}};
  adjList[1] = {{0, 10}, {3, 15}};
  adjList[2] = {{0, 6}, {3, 4}};
  adjList[3] = {{0, 5}, {1, 15}, {2, 4}};

  int mstWeight = primMST(V, adjList);
  std::cout << "Total weight of MST is " << mstWeight << std::endl;
  return 0;
}
