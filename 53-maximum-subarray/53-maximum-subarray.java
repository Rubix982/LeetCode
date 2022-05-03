class Solution {    
    public int maxSubArray(int[] nums) {
        // int[] dp = new int[nums.length];

        // dp[0] = nums[0];
        int max = Integer.MIN_VALUE;
        int sum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            // dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
            // max = Math.max(dp[i], max);
            sum += nums[i];
            
            max = Math.max(max, sum);
            
            if (sum < 0) { sum = 0; }
        }
        return max;
    }
}