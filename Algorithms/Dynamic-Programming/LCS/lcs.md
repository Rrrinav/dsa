# Longest Common Subsequence (LCS) Using Dynamic Programming

The **Longest Common Subsequence (LCS)** problem is a classic dynamic programming challenge. It involves finding the longest subsequence that appears in the same order in two given strings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original strings.

---

## Problem Statement

Given two strings, `X` of length `m` and `Y` of length `n`, find the length of their longest common subsequence.

### Example

- **Input**: `X = "AGGTAB"`, `Y = "GXTXAYB"`
- **Output**: `LCS = "GTAB"`, Length = 4

---

## Dynamic Programming Approach

### Recurrence Relation

Let `dp[i][j]` represent the length of the LCS of the first `i` characters of `X` and the first `j` characters of `Y`.

1. **Base Case**:

   - If either string is empty, `dp[i][0] = 0` or `dp[0][j] = 0`.

2. **Recursive Case**:
   - If `X[i-1] == Y[j-1]`:  
     `dp[i][j] = dp[i-1][j-1] + 1`
   - Otherwise:  
     `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

### Algorithm Steps

1. **Initialize** a 2D array `dp` of size `(m+1) x (n+1)` with zeros.
2. **Iterate** over both strings:
   - For each `i` from 1 to `m`:
     - For each `j` from 1 to `n`:
       - Update `dp[i][j]` using the recurrence relation.
3. **Extract Result**:
   - The value of `dp[m][n]` gives the length of the LCS.
4. **Backtrack** (Optional):
   - To reconstruct the LCS, backtrack through the `dp` table.

---

## Example Walkthrough

### Input

- `X = "AGGTAB"`
- `Y = "GXTXAYB"`

### DP Table

| i\j |     | G   | X   | T   | X   | A   | Y   | B   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| A   | 0   | 0   | 0   | 0   | 0   | 1   | 1   | 1   |
| G   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
| G   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
| T   | 0   | 1   | 1   | 2   | 2   | 2   | 2   | 2   |
| A   | 0   | 1   | 1   | 2   | 2   | 3   | 3   | 3   |
| B   | 0   | 1   | 1   | 2   | 2   | 3   | 3   | 4   |

### Result

- LCS Length: `dp[6][7] = 4`
- LCS: `"GTAB"` (retrieved by backtracking).

---

## Time Complexity

- **Table Construction**: Filling the `dp` table requires iterating over all `i` and `j` pairs.
  - **Time Complexity**: **O(m \* n)**

## Space Complexity

- **Space for DP Table**: The table has dimensions `(m+1) x (n+1)`.
  - **Space Complexity**: **O(m \* n)**
- **Optimized Space**: Only the current and previous rows are needed for calculation, reducing space complexity to **O(n)**.

---

## Benefits of Dynamic Programming for LCS

1. **Efficiency**:
   - Significantly faster than recursive approaches with exponential time complexity.
2. **Clear Solution**:
   - DP table provides a clear way to track intermediate results and the optimal solution.

---

## Comparison with Other Methods

- **Recursive Approach**:
  - Time Complexity: **O(2^n)** (due to overlapping subproblems).
  - Space Complexity: **O(n)** (due to recursion stack).
- **Dynamic Programming**:
  - Time Complexity: **O(m \* n)**.
  - Space Complexity: **O(m \* n)** (or **O(n)** with optimization).

---

## Conclusion

Dynamic Programming provides an efficient and elegant solution for the Longest Common Subsequence problem, making it practical for real-world applications like DNA sequence analysis, text comparison, and version control systems.
