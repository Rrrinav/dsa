# Knapsack problem

A classic optimization problem

## Problem Statement

**Given:**

- A set of items, each with a specific weight and value.
- A knapsack with a maximum weight capacity.

**Goal:**

- Select items to maximize the total value without exceeding the knapsack’s weight limit.

## Greedy Solution

Greedy method works well for only _fractional knapsack problem_. For 0/1 knapsack problem we should use Dynamic programming solutions.

**Steps:**

- Calculate the Value-to-Weight Ratio: For each item, compute the value-to-weight ratio.
- Sort Items by Ratio: Sort the items in descending order of their value-to-weight ratio.
- Pick Items by Ratio: Start from the top of the sorted list and add items to the knapsack until it’s full.
  If an item can’t fit entirely, take the maximum fraction of it that will fit.

### Example

Suppose you have a knapsack with a capacity of 50 units and the following items:

| Item | Weight | Value | Value-to-Weight Ratio |
| ---- | ------ | ----- | --------------------- |
| 1    | 10     | 60    | 6                     |
| 2    | 20     | 100   | 5                     |
| 3    | 30     | 120   | 4                     |

#### Following the Greedy Steps

1. **Sort items by ratio**: Item 1 (6), Item 2 (5), Item 3 (4).
2. **Add items in this order**:
   - Add all of Item 1 (10 units, value = 60).
   - Add all of Item 2 (20 units, value = 100).
   - Add 2/3rd of Item 3 (20 units, value = 2/3 \* 120 = 80).

#### Total Value

60 + 100 + 80 = 240
