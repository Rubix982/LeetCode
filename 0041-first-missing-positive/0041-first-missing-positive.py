class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = set(nums)
        smallest_positive = 1

        while smallest_positive in nums:
            smallest_positive += 1

        return smallest_positive
