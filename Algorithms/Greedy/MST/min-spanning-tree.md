# Minimum spanning tree

Minimum spanning tree (MST) is a subset of edges in a connected, edge-weighted graph that connects all the vertices together with the minimum possible total edge weight.

There are two greedy methods to find minimum spanning trees:

1. `Prim's algorithm`: Starts from an arbitrary vertex and adds the shortest edge that connects the tree to a new vertex.
2. `Kruskal's algorithm`: Sorts all the edges by weight and adds them one by one, avoiding cycles.

## Prims's algorithm

**Steps:**

1. **Start with any edge:** Initialize an empty tree `T` with a single vertex.
2. **Find the shortest edge:** Find the shortest edge that connects any vertex in `T` to a vertex outside `T`.
3. **Add the edge:** Add this edge to `T`.
4. **Repeat:** Repeat steps 2 and 3 until all vertices are in `T`.

## Kruskal's algorithm

**Steps:**

1. **Sort the edges:** Sort all the edges in non-decreasing order of their weight.
2. **Add the smallest edge:** Add the smallest edge to the tree, avoiding cycles.
3. **Repeat:** Repeat step 2 until `T` has `n-1` edges.

## Summary

| Feature                        | Kruskal’s Algorithm                                     | Prim’s Algorithm                                                          |
| ------------------------------ | ------------------------------------------------------- | ------------------------------------------------------------------------- |
| **Approach**                   | Edge-based; selects edges in increasing order of weight | Vertex-based; starts from an arbitrary vertex, adding edges to expand MST |
| **Graph Type Suitability**     | Works better for sparse graphs                          | Works better for dense graphs                                             |
| **Data Structures Used**       | Union-Find for cycle detection, and sorted edge list    | Priority queue (min-heap) or adjacency list                               |
| **Cycle Handling**             | Union-Find efficiently checks and prevents cycles       | No explicit cycle check; always connects new vertices                     |
| **Running Time Complexity**    | O(E log E) due to edge sorting                          | O(E log V) with a priority queue                                          |
| **Number of Edges Considered** | Considers edges in non-decreasing weight order          | Only edges connecting MST vertices to non-MST vertices                    |
