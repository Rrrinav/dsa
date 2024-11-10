# Branch and Bound

The Branch and Bound (B&B) algorithm is a general algorithmic method for finding optimal solutions to various types of optimization problems.

## How algorithm works?

1. Problem Definition and Bounding:
   You start with an initial problem and determine a way to bound solutions, meaning you estimate the best possible solution within a sub-problem.
   A bound helps to identify whether a branch (subset of the solution space) is worth exploring further.

2. Branching:
   Divide (or "branch") the problem into smaller sub-problems. Each sub-problem represents a subset of potential solutions.
   For example, in the Traveling Salesman Problem (TSP), a branch might represent including or excluding a specific path.

3. Bounding Each Sub-problem:
   Calculate a bound (best possible solution) for each sub-problem.
   If the bound of a sub-problem is worse than the current best-known solution, you prune that branch (ignore it) since it can’t yield a better solution.
   If the bound is better, the sub-problem remains a candidate for further exploration.

4. Pruning:
   Prune sub-problems that are guaranteed to not yield better solutions than the best one already found.
   This process cuts down on the amount of work since it eliminates large parts of the search space.

   - **Search Strategies**:
     1. `Depth-First Search (DFS)`: Explore one branch fully until it’s exhausted, then backtrack.
     2. `Breadth-First Search (BFS)`: Explore all sub-problems at one level before moving to the next.
     3. `Best-First Search (least cost search)`: Choose the sub-problem with the best bound, allowing the algorithm to find optimal solutions faster.

5. Termination:
   The algorithm terminates when all branches have been explored or pruned.
   The best solution found during the process is the optimal solution.

## Short explanation

```
┌───────────────────────────┐  ┌─────────────┐  ┌──────────────────────────────┐  ┌──────┐  ┌─────────────────────┐  ┌────────────────┐  ┌─────────┐
│Branch into smaller problem│->│Start solving│->│Discard if not optimal (Prune)│->│Repeat│->│Complete all branches│->│Optimal solution│->│Terminate│
└───────────────────────────┘  └─────────────┘  └──────────────────────────────┘  └──────┘  └─────────────────────┘  └────────────────┘  └─────────┘
```
