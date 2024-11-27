# Travelling Salesman Problem (TSP) Using Dynamic Programming (With Visited Array)

Given a set of cities and the distances between every pair of cities, find the shortest possible route that visits each city exactly once and returns to the origin city.

---

## Key Points

- **Input**: A weighted graph represented by a distance matrix.
- **Output**: The minimum cost of visiting all cities exactly once and returning to the start.
- **Constraints**:
  - All cities must be visited exactly once.
  - Return to the starting city.

---

## Dynamic Programming Approach

### Key Idea

- Use **Dynamic Programming (DP)** to solve TSP by breaking it into subproblems.
- The state is defined by:
  - A **current city**.
  - A **visited array** indicating which cities have been visited.

---

### Steps

1. **Define the State**:

   - Let `dp(city, visited)` represent the minimum cost to visit all cities in the `visited` array (true if visited) and end at `city`.

2. **Base Case**:

   - If all cities have been visited:

     ```text
     return dist[city][start]
     ```

     This represents the cost of returning to the starting city.

3. **Transition**:

   - For the current city, try moving to all unvisited cities:

     ```text
     dp(city, visited) = min(
         dp(next_city, visited_after_visiting_next) + dist[city][next_city]
     )
     ```

4. **Final Answer**:

   - Start from the initial city with only it marked as visited:

     ```text
     dp(start, visited) for all cities visited
     ```

---

## Algorithm (Pseudo-Code)

```text
function tsp(city, visited):
    if all cities are visited:
        return dist[city][start]  # cost to return to start

    if dp[city][visited] is not None:
        return dp[city][visited]

    result = infinity
    for next_city in 1 to n:
        if not visited[next_city]:
            visited[next_city] = true
            result = min(result, tsp(next_city, visited) + dist[city][next_city])
            visited[next_city] = false

    dp[city][visited] = result
    return result

main:
    visited = [false] * (n + 1)
    visited[start] = true
    print(tsp(start, visited))
```

## Complexity

Time Complexity: O(n.2^n) (Recursive exploration of states).
Space Complexity: O(n.2^n) for DP table and recursion stack.
