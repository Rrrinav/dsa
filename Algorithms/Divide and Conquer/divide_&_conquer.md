# Divide and Conquer

Divide and conquer is a strategy for solving problems that can be divided into individual sub-problems

## Basic Idea

**Divide**: Break the problem into smaller, non-overlapping sub-problems. These sub-problems should be easier to solve.
**Conquer**: Recursively solve each sub-problem.
**Combine**: Combine the solutions of the sub-problems to form the solution to the original problem.

## Examples

1. `Merge Sort`: Divides the array into two halves, sorts each half recursively, and then merges the sorted halves.
2. `Quick Sort`: Selects a pivot element, divides the array into two parts (elements smaller than the pivot and elements greater than the pivot), and recursively sorts the two parts.
3. `Binary Search`: Recursively divides a sorted array in half, comparing the middle element with the target value to narrow the search.
4. `Strassen’s Matrix Multiplication`: Divides matrices into smaller sub-matrices, recursively multiplies them, and combines them to get the result.

## Recurrence relation

T(n) = a T(n/b) + O(n^d)

- `a` is the number of subproblems.
- `n/b` is the size of each subproblem.
- `O(n^d)` is the cost of dividing and combining the subproblems.

> !> [!TIP]
> Merge sort just sucks, use quick sort and if size < 5 use bubble sort (specially if <= 3, hard code it using `if-else` ladder or something)

## Difference between D&C and DP

| **Aspect**                  | **Divide and Conquer**                                          | **Dynamic Programming**                                              |
| --------------------------- | --------------------------------------------------------------- | -------------------------------------------------------------------- |
| **Approach**                | Breaks the problem into smaller subproblems and solves them     | Breaks the problem into subproblems and solves them optimally,       |
|                             | independently.                                                  | reusing solutions to subproblems.                                    |
| **Overlapping Subproblems** | Subproblems are generally non-overlapping.                      | Subproblems overlap and solutions are reused.                        |
| **Optimal Substructure**    | Combines solutions from subproblems without reusing previous    | Each subproblem solution is reused to build the final result.        |
|                             | solutions.                                                      |                                                                      |
| **Memoization**             | No memoization; subproblems are solved independently each time. | Uses memoization (or tabulation) to store results and avoid          |
|                             |                                                                 | redundant computations.                                              |
| **Example Algorithms**      | Merge Sort, Quick Sort, Binary Search, Strassen’s Matrix        | Fibonacci, Longest Common Subsequence, 0/1 Knapsack, Matrix          |
|                             | Multiplication.                                                 | Chain Multiplication.                                                |
| **Time Complexity**         | Time complexity often depends on the number of subproblems and  | Time complexity is typically reduced by solving each subproblem only |
|                             | how they are combined (e.g., O(n log n) for Merge Sort).        | once (e.g., O(n) for Fibonacci with memoization).                    |
