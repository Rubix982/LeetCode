# 213. House Robber II (MEDIUM)

## Table Of Contents

- [213. House Robber II (MEDIUM)](#213-house-robber-ii-medium)
  - [Table Of Contents](#table-of-contents)
  - [Link](#link)
  - [Description](#description)
  - [Hints](#hints)
  - [Result Details](#result-details)

## Link

Problem can be found [here](https://leetcode.com/problems/house-robber-ii/).

## Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

```text
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

Example 2:

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

Example 3:

```text
Input: nums = [1,2,3]
Output: 3
```

Constraints:

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## Hints

Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.

## Result Details

...
