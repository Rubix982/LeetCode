class Solution {
    public boolean canJump(int[] nums) {
        int s = (nums.length) - 2;
        int t = (nums.length) - 1;

        while (s >= 0) {
            if (nums[s] + s >= t) {
                t = s;
            }

            s -= 1;
        }

        return t == 0;
    }
}
