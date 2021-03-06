# 70. Climbing Stairs (EASY)

## Table Of Contents

- [70. Climbing Stairs (EASY)](#70-climbing-stairs-easy)
  - [Table Of Contents](#table-of-contents)
  - [Link](#link)
  - [Description](#description)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Hint](#hint)
  - [Result Details](#result-details)

## Link

Problem can be found [here](https://leetcode.com/problems/min-cost-climbing-stairs/).

## Description

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

### Example 1

```text
Input: cost = [10,15,20]
Output: 15
```

Explanation: You will start at index 1.

- Pay 15 and climb two steps to reach the top.

The total cost is 15.

### Example 2

```text
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
```

Explanation: You will start at index 0.

- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.

The total cost is 6.
 
### Constraints

```text
2 <= cost.length <= 1000
0 <= cost[i] <= 999
```

## Hint

To reach nth step, what could have been your previous steps? (Think about the step sizes)

## Result Details

Runtime: `1 ms`, faster than `84.31%` of Java online submissions for Min Cost Climbing Stairs.

Memory Usage: `42.1 MB`, less than `82.52%` of Java online submissions for Min Cost Climbing Stairs.
