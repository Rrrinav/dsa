#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Edge
{
  int src, dest, weight;
};

void bellmanFord(int vertices, vector<Edge> &graph, int source)
{
  vector<int> distance(vertices, numeric_limits<int>::max());
  distance[source] = 0;

  cout << "Initial distances:\n";
  for (int i = 0; i < vertices; i++)
    cout << "Vertex " << i << ": " << (distance[i] == numeric_limits<int>::max() ? "INF" : to_string(distance[i])) << "\n";
  cout << "\n";

  // Relax all edges (V-1) times
  for (int i = 1; i < vertices; i++)
  {
    cout << "Iteration " << i << ":\n";
    bool updated = false;
    for (const auto &edge : graph)
    {
      if (distance[edge.src] != numeric_limits<int>::max() && distance[edge.src] + edge.weight < distance[edge.dest])
      {
        distance[edge.dest] = distance[edge.src] + edge.weight;
        updated = true;
        cout << "Updated distance of vertex " << edge.dest << " to " << distance[edge.dest] << " via edge (" << edge.src << " -> "
             << edge.dest << ", weight: " << edge.weight << ")\n";
      }
    }
    if (!updated)
    {
      cout << "No updates in this iteration. Exiting early.\n";
      break;
    }
    cout << "\n";
  }

  // Check for negative weight cycles
  cout << "Checking for negative weight cycles...\n";
  for (const auto &edge : graph)
  {
    if (distance[edge.src] != numeric_limits<int>::max() && distance[edge.src] + edge.weight < distance[edge.dest])
    {
      cout << "Graph contains a negative weight cycle.\n";
      return;
    }
  }

  // Print shortest distances
  cout << "\nFinal distances:\n";
  for (int i = 0; i < vertices; i++)
    cout << "Vertex " << i << ": " << (distance[i] == numeric_limits<int>::max() ? "INF" : to_string(distance[i])) << "\n";
}

int main()
{
  int vertices = 4;

  vector<Edge> graph = {{0, 1, 1}, {1, 2, 3}, {2, 3, -2}, {0, 2, 4}, {3, 1, -1}};

  int source = 0;  // Hardcoded source vertex

  cout << "Performing Bellman-Ford algorithm on hardcoded graph data...\n";
  bellmanFord(vertices, graph, source);

  return 0;
}
