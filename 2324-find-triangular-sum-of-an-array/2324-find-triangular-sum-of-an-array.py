class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        for _ in range(n - 1):
            for i in range(n - 1):
                nums[i] = (nums[i] + nums[i + 1]) % 10
            n -= 1  # Reduce the effective size of the array
        return nums[0]

        while len(nums) != 1:
            nums = [(nums[i] + nums[i+1]) % 10 for i in range(len(nums) - 1)]

        return nums[0]
        