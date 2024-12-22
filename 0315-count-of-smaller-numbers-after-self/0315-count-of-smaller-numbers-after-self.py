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
        nums_with_indices = [(nums[i], i) for i in range(n)]
        
        self.merge_sort(nums_with_indices, 0, n - 1, results)
        return results


    def merge_sort(self, nums: List[tuple], start: int, end: int, results: List[int]):
        if start >= end:
            return

        mid = (start + end) // 2
        self.merge_sort(nums, start, mid, results)
        self.merge_sort(nums, mid + 1, end, results)

        # Merge and count smaller elements
        self.merge(nums, start, mid, end, results)

    def merge(self, nums: List[tuple], start: int, mid: int, end: int, results: List[int]):
        left = start
        right = mid + 1
        temp = []
        right_counter = 0

        while left <= mid and right <= end:
            if nums[left][0] > nums[right][0]:
                right_counter += 1
                temp.append(nums[right])
                right += 1
            else:
                results[nums[left][1]] += right_counter
                temp.append(nums[left])
                left += 1

        # Add any remaining elements
        while left <= mid:
            results[nums[left][1]] += right_counter
            temp.append(nums[left])
            left += 1
        while right <= end:
            temp.append(nums[right])
            right += 1

        # Copy back to the original array
        nums[start:end + 1] = temp
