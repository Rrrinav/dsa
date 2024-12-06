# Comparison of Dijkstra, Bellman-Ford, and Floyd-Warshall Algorithms

## Overview

Graph algorithms are essential for solving shortest path problems in weighted graphs. Dijkstra, Bellman-Ford, and Floyd-Warshall are three popular algorithms, each with unique use cases, advantages, and trade-offs. Below is a detailed comparison of these algorithms.

---

## 1. **Dijkstra's Algorithm**

### Key Features

- Solves the single-source shortest path problem.
- Works with **non-negative edge weights** only.
- Greedy algorithm.

### Time Complexity

- **Using adjacency matrix**: `O(V^2)`
- **Using adjacency list with a priority queue**: `O((V + E) log V)`

### Advantages

- Fast and efficient for graphs with non-negative weights.
- Suitable for dense graphs when using an adjacency matrix.

### Disadvantages

- Cannot handle negative weight edges.
- Needs a priority queue for optimal performance in sparse graphs.

### Use Cases

- Navigation systems (e.g., Google Maps).
- Network routing protocols.

---

## 2. **Bellman-Ford Algorithm**

### Key Features

- Solves the single-source shortest path problem.
- Can handle **negative weight edges**.
- Dynamic programming approach.

### Time Complexity

- `O(V * E)`

### Advantages

- Detects negative weight cycles.
- Works for all types of weighted graphs (positive and negative weights).

### Disadvantages

- Slower than Dijkstra's algorithm.
- Not efficient for dense graphs.

### Use Cases

- Financial models involving profits/losses (negative weights).
- Systems where negative weight edges are expected.

---

## 3. **Floyd-Warshall Algorithm**

### Key Features

- Solves the **all-pairs shortest path problem**.
- Uses a dynamic programming approach.
- Works for graphs with positive or negative weights but **no negative cycles**.

### Time Complexity

- `O(V^3)`

### Advantages

- Simple to implement.
- Finds shortest paths between all pairs of vertices in one run.

### Disadvantages

- Inefficient for sparse graphs due to cubic time complexity.
- High memory usage for large graphs.

### Use Cases

- Finding shortest paths in dense networks.
- Analyzing network graphs or flight routes.

---

## Comparison Table

| Algorithm      | Problem Type                | Handles Negative Weights? | Detects Negative Cycles? | Time Complexity    | Space Complexity | Use Cases                           |
| -------------- | --------------------------- | ------------------------- | ------------------------ | ------------------ | ---------------- | ----------------------------------- |
| Dijkstra       | Single-source shortest path | No                        | No                       | `O((V + E) log V)` | `O(V + E)`       | Routing, navigation                 |
| Bellman-Ford   | Single-source shortest path | Yes                       | Yes                      | `O(V * E)`         | `O(V)`           | Financial models, general use cases |
| Floyd-Warshall | All-pairs shortest path     | Yes                       | No                       | `O(V^3)`           | `O(V^2)`         | Dense networks, graph analysis      |

---

## Summary

- **Dijkstra** is the fastest for single-source shortest path problems when weights are non-negative.
- **Bellman-Ford** is versatile, handling negative weights and detecting negative cycles, but slower than Dijkstra.
- **Floyd-Warshall** is comprehensive, solving all-pairs shortest path problems, but inefficient for large or sparse graphs.

Choose the algorithm based on the problem constraints, graph structure, and performance requirements.
