class ArrayValWithOrigIdx:
    def __init__(self, val: int, original_idx: int):
        self.val = val
        self.original_idx = original_idx

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if not nums:
            return []

        results = [0] * n
        array_with_indices = [ArrayValWithOrigIdx(nums[i], i) for i in range(n)]
        
        self.merge_sort_and_count(array_with_indices, 0, n - 1, results)
        return results

    def merge_sort_and_count(self, nums: List[ArrayValWithOrigIdx], start: int, end: int, results: List[int]):
        if start >= end:
            return

        mid = (start + end) // 2
        self.merge_sort_and_count(nums, start, mid, results)
        self.merge_sort_and_count(nums, mid + 1, end, results)

        left_pos = start
        right_pos = mid + 1
        merged = []
        right_counter = 0

        # Merge and count
        while left_pos <= mid and right_pos <= end:
            if nums[left_pos].val > nums[right_pos].val:
                right_counter += 1
                merged.append(nums[right_pos])
                right_pos += 1
            else:
                results[nums[left_pos].original_idx] += right_counter
                merged.append(nums[left_pos])
                left_pos += 1

        # Add remaining left elements
        while left_pos <= mid:
            results[nums[left_pos].original_idx] += right_counter
            merged.append(nums[left_pos])
            left_pos += 1

        # Add remaining right elements
        while right_pos <= end:
            merged.append(nums[right_pos])
            right_pos += 1

        # Copy back to the original array
        for i in range(len(merged)):
            nums[start + i] = merged[i]
