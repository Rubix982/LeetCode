class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int prev = nums[0], secondPrev = 0, current;

        for (int i = 1; i < nums.length; i++) {

            current = nums[i] + secondPrev;
            current = Math.max(current, prev);

            secondPrev = prev;
            prev = current;
        }
        return prev;
    }
}