# 1567. Maximum Length Of Subarray With Positive Product (MEDIUM)

## Table Of Contents

- [1567. Maximum Length Of Subarray With Positive Product (MEDIUM)](#1567-maximum-length-of-subarray-with-positive-product-medium)
  - [Table Of Contents](#table-of-contents)
  - [Description](#description)
  - [Hints](#hints)
  - [Result Details](#result-details)

## Description

Given an array of integers `nums`, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

Example 1:

```text
Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
```

Example 2:

```text
Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
```

Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

Example 3:

```text
Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
```

Constraints:

- `1 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`

## Hints

- Split the whole array into subarrays by zeroes since a subarray with positive product cannot contain any zero.
- If the subarray has even number of negative numbers, the whole subarray has positive product.
- Otherwise, we have two choices, either - remove the prefix till the first negative element in this subarray, or remove the suffix starting from the last negative element in this subarray.

## Result Details

...
