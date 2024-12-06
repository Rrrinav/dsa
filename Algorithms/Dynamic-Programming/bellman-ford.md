# Bellman-Ford Algorithm

The Bellman-Ford algorithm is a graph algorithm that computes the shortest paths from a single source vertex to all other vertices in a weighted graph. It is capable of handling graphs with negative weight edges and can detect negative weight cycles.

---

## **Algorithm Steps**

1. **Initialization**:

   - Set the distance to all vertices as infinity (`INF`), except the source vertex, which is set to 0.

2. **Relaxation**:

   - Perform `(V-1)` iterations, where `V` is the number of vertices.
   - For each edge `(u, v)` with weight `w`:
     - If `distance[u] + w < distance[v]`, update `distance[v] = distance[u] + w`.

3. **Cycle Detection**:
   - Perform one more iteration to check for negative weight cycles.
   - If further relaxation is possible, a negative weight cycle exists.

---

## **Time Complexity**

1. **Initialization**:

   - Takes O(V), where V is the number of vertices.

2. **Relaxation**:

   - Takes O(E) per iteration, where E is the number of edges.
   - Total for (V-1) iterations: O(V \* E).

3. **Cycle Detection**:
   - Takes O(E).

### Overall Time Complexity

- **Best Case**: O(E) (if early stopping optimization is applied).
- **Average Case**: O(V \* E).
- **Worst Case**: O(V \* E).

---

## **Space Complexity**

- O(V) for storing distances and graph representation.

---

## **Advantages**

1. Handles negative weight edges, unlike Dijkstra's algorithm.
2. Can detect negative weight cycles.

---

## **Disadvantages**

1. Slower than Dijkstra's algorithm for graphs without negative weights.
2. Does not work for graphs with negative weight cycles (paths cannot be reliably determined).

---

## **Applications**

1. **Network Routing**:
   - Used in distance vector routing protocols.
2. **Arbitrage Detection**:
   - Detects arbitrage opportunities in currency exchange rates by modeling rates as graph weights.
3. **Shortest Path Problems**:
   - Used in situations where negative weights are present.

---

## **Example**

### Graph

Vertices: {A, B, C, D}
Edges:

- A → B (weight: 1)
- B → C (weight: 3)
- C → D (weight: -2)
- A → C (weight: 4)

### Steps

1. Initialization:
   Distance = {A: 0, B: INF, C: INF, D: INF}

2. Iteration 1:
   Relax edges:

   - a → b: distance(b) = 1
   - b → c: distance(c) = 4
   - c → d: distance(d) = 2
     distance = {a: 0, B: 1, C: 4, D: 2}

3. Iteration 2:
   No changes as all distances are already minimal.

4. Check for negative cycles:
   No further relaxation possible.

Shortest distances:
A → B: 1
A → C: 4
A → D: 2
