class Solution {    
    public int maxSubArray(int[] nums) {
        
        if (nums.length == 1) {
            return nums[0];
        }
        
        int[] dp = new int[nums.length];
        
        // for (int i = 0; i < nums.length; i++) {
        //     dp[i] = 0;
        // }
        
        dp[0] = nums[0];
        int max = dp[0];
        
        for (int i = 1; i < nums.length; i++) {
            // System.out.println(dp[i-1] + nums[i]);
            // System.out.println(nums[i]);
            dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
            max = Math.max(dp[i], max);
        }

//         for (int i = 0; i < nums.length; i++) {

//         }
                    
        return max;
    }
}