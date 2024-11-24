// We are using least cost on Dijkstra
#include <limits>
#include <queue>
#include <vector>

const int INF = std::numeric_limits<int>::max();
typedef std::vector<std::vector<std::pair<int, int>>> Graph;
std::vector<int> least_cost_search(int start, const Graph &graph)
{
  int n = graph.size();
  std::vector<int> distance(n, INF);

  distance[start] = 0;  // start node

  // Min heap (priority queue)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  pq.push({0, start});  // cost, node

  while (!pq.empty())
  {
    int current_cost = pq.top().first;
    int current_node = pq.top().second;
    pq.pop();

    // If we have already found a better path we can ignore this node
    // distance[current_node] is the smallest distance to reach current_node
    if (distance[current_node] < current_cost)
      continue;

    for (const auto &neighbours : graph[current_node])
    {
      int neighbour = neighbours.first;
      int weight = neighbours.second;
      int new_cost = current_cost + weight;
      if (new_cost < distance[neighbour])
      {
        distance[neighbour] = new_cost;
        pq.push({new_cost, neighbour});
      }
    }
  }
  return distance;
}

int main(void)
{
  int n = 5;  // Number of nodes
  Graph graph(n);

  // Example graph edges (node, weight)
  graph[0].push_back({1, 10});
  graph[0].push_back({2, 3});
  graph[1].push_back({2, 1});
  graph[1].push_back({3, 2});
  graph[2].push_back({1, 4});
  graph[2].push_back({3, 8});
  graph[2].push_back({4, 2});
  graph[3].push_back({4, 7});
  graph[4].push_back({3, 9});

  int startNode = 0;
  least_cost_search(startNode, graph);

  return 0;
}
