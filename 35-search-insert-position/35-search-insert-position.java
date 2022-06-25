class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            boolean check = nums[i] == target || nums[i] > target;            
            if (check) {
                return i;
            }
        }
        
        return nums.length;
    }
}