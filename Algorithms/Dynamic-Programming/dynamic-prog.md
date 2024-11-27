# Dynamic Programming (DP) Notes

Dynamic Programming is a technique for solving problems by breaking them into overlapping subproblems and solving each subproblem only once, storing the results for future use (memoization or tabulation).

Key characteristics of problems suited for DP:

- **Optimal Substructure**: The problem can be broken down into smaller, similar subproblems.
- **Overlapping Subproblems**: Subproblems recur multiple times during the computation.

---

## Types of DP Approaches

### 1. **Top-Down Approach (Memoization)**

- Solve the problem recursively.
- Store the results of solved subproblems in a table to avoid redundant calculations.

### 2. **Bottom-Up Approach (Tabulation)**

- Iteratively solve all possible subproblems.
- Build the solution starting from the smallest subproblems.

---

## Steps to Solve a DP Problem

1. **Understand the Problem**:

   - Analyze the problem statement and constraints.
   - Determine if the problem exhibits optimal substructure and overlapping subproblems.

2. **Define the State**:

   - Decide on a state `dp[i][j]` that represents the solution to a subproblem.
   - Example: `dp[i]` could represent the minimum cost to reach step `i`.

3. **Formulate the Recurrence Relation**:

   - Express the solution for a state in terms of previously computed states.

4. **Initialize the Base Cases**:

   - Identify trivial cases where the solution is directly known.

5. **Iterate (Bottom-Up) or Recur (Top-Down)**:

   - Compute all subproblems iteratively or recursively.

6. **Extract the Final Solution**:
   - Use the DP table to retrieve the solution to the original problem.

---

## Common Problems and Examples

### 1. **Fibonacci Sequence**

#### Problem

Find the `n`-th Fibonacci number.

#### Solution

State: `dp[i]` represents the `i`-th Fibonacci number.

Recurrence Relation:  
dp(i) = dp(i-1) + dp(i-2)

Base Cases:
dp(0) = 0,
dp(1) = 1

```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```
