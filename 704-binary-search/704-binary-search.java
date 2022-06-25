class Solution {
    public int search(int[] nums, int target) {
        return binarySearch(nums, target, 0, nums.length - 1);
    }
    
    public int binarySearch(int[] nums, int target, int min, int max) {
        if (nums[min] == target)
        {
            return min;
        }
        
        if (nums[max] == target)
        {
            return max;
        }
        
        int ave = (min+max)/2;
        
        if (nums[ave] == target) {
            return ave;
        }
        
        if (nums[min] > target || nums[max] < target) {
            return -1;
        }
        
        if (nums[ave] < target) {
            return binarySearch(nums, target, ave + 1, max);
        }
        else
        {
            return binarySearch(nums, target, min, ave - 1);
        }
    }
}