public class Solution {
    int rob(int[] nums) {

        int N = nums.length;

        if (N == 0) {
            return 0;
        }

        if (N == 1) {
            return nums[0];
        }

        if (N == 2) {
            return Math.max(nums[0], nums[1]);
        }

        if (N == 3) {
            return Math.max(nums[0], Math.max(nums[1], nums[2]));
        }

        int[] dp_1 = new int[N];
        dp_1[0] = nums[0];
        dp_1[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < N - 1; i++) {
            dp_1[i] = Math.max(nums[i] + dp_1[i - 2], dp_1[i - 1]);
        }

        int[] dp_2 = new int[N];
        dp_2[0] = 0;
        dp_2[1] = nums[1];
        dp_2[2] = Math.max(nums[1], nums[2]);

        for (int i = 3; i < N; i++) {
            dp_2[i] = Math.max(nums[i] + dp_2[i - 2], dp_2[i - 1]);
        }

        return Math.max(dp_1[N - 2], dp_2[N - 1]);
    }
}
