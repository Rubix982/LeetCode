class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for i in range(k):
            min_val, min_idx = 2 ** 31 - 1, -1
            for jdx, val in enumerate(nums):
                if val < min_val:
                    min_val = val
                    min_idx = jdx
            nums[min_idx] = nums[min_idx] * multiplier

        return nums
