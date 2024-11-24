# Shortest path algorithms

- [Dijkstra's algorithm](#dijkstras-algorithm) : For single source shortest path
- [Floyd-Warshall algorithm](#floyd-warshall-algorithm) : For all pairs shortest path

## Dijkstra's algorithm

## Floyd-Warshall algorithm

Floyd-Warshall is a **dynamic programming algorithm** used to find the **shortest paths between all pairs of vertices** in a weighted graph. The graph can have both positive and negative edge weights but must not contain negative weight cycles.

---

### **How Floyd-Warshall Works**

1. **Input**: A weighted graph represented as an adjacency matrix `dist`:

   - If there's an edge from u to v with weight w, `dist[u][v] = w`.
   - If no edge exists, `dist[u][v] = ∞`.
   - `dist[u][u] = 0` (distance from a vertex to itself is 0).

2. **Core Idea**:

   - Gradually improve the estimate of the shortest path by considering one vertex at a time as an intermediate point.
   - If vertex k can be used as an intermediate vertex between u and v, update the shortest distance as:
     dist(u)(v) = min(dist(u)(v),dist(u)(k)+dist(k)(v))

3. **Algorithm**:

   - For each vertex k, check all pairs of vertices (u, v).
   - Update the shortest path `dist[u][v]` by considering paths through k.

4. **Output**: The matrix `dist`, where `dist[u][v]` is the shortest distance from u to v .

---

### **Algorithm Steps**

1. **Initialization**:

   - Start with the given adjacency matrix (use ∞ for no edge).

2. **Dynamic Programming**:

   - For each vertex k :
     - For each vertex u :
       - For each vertex v :
         dist(u)(v) = dist(u)(v), dist(u)(k) + dist(k)(v))

3. **Result**:
   - The `dist` matrix now contains the shortest paths between all pairs of vertices.

---

### **Pseudocode**

```text
function floydWarshall(dist):
    n = size of dist

    for k from 0 to n-1:
        for u from 0 to n-1:
            for v from 0 to n-1:
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v])

    return dist
```

---

---

### **Example**

#### Input Graph

Adjacency matrix representation:

|0 3 ∞ 7|
|8 0 2 ∞|
|5 ∞ 0 1|
|2 ∞ ∞ 0|

#### Output Shortest Path Matrix

|0 3 5 6|
|7 0 2 3|
|5 8 0 1|
|2 5 7 0|

---

### **Time Complexity**

- **Overall**: O(V^3)
- **Space Complexity**: O(V^2), as it uses an adjacency matrix.

---

### **Key Features**

- Handles graphs with negative edge weights (but no negative weight cycles).
- Finds shortest paths between all pairs of vertices.
- Simple to implement using dynamic programming.

Let me know if you'd like me to expand on any part!
