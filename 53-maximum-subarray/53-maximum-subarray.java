class Solution {    
    public int maxSubArray(int[] nums) {
        
        if (nums.length == 1) {
            return nums[0];
        }
        
        int[] dp = new int[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            dp[i] = 0;
        }
        
        dp[0] = nums[0];
        int max = -10001;
        
        for (int i = 1; i < nums.length; i++) {
            // System.out.println(dp[i-1] + nums[i]);
            // System.out.println(nums[i]);
            dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
        }

        for (int i = 0; i < nums.length; i++) {
            max = Math.max(dp[i], max);
        }
                    
        return max;
    }
}