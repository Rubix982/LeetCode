class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # nums = set(nums)
        # smallest_positive = 1

        # while smallest_positive in nums:
        #     smallest_positive += 1

        # return smallest_positive

        n = len(nums)

        # Place each number in its correct position if possible
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        # Find the first missing positive
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # If all positions are filled correctly, the missing number is n + 1
        return n + 1
