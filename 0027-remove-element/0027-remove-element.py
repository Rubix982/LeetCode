class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        index = 0
        for num in nums:
            if num != val:
                nums[index] = num
                index += 1
        return index

        len_nums = len(nums)
        count = 0
        for i in range(0, len_nums):
            if i >= len(nums):
                continue

            if nums[i] != val:
                continue

            if i + 1 == len_nums:
                count += 1
                nums[i] = val + 1
                break

            start = i
            end = i + 1
            while end < len_nums and nums[end] == val:
                end += 1

            count += end - start
            nums[start:end] = nums[end:len_nums]
        
        return len_nums - count