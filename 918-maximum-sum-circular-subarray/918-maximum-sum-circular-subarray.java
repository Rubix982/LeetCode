class Solution {
    public int maxSubarraySumCircular(int[] nums) {
    
        int total = 0;
        int maxVal = Integer.MIN_VALUE;
        int minVal = Integer.MAX_VALUE;
        int currMax = 0;
        int currMin = 0;
        
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            
            currMax = Math.max(currMax + nums[i], nums[i]);
            maxVal = Math.max(maxVal, currMax);
            
            currMin = Math.min(currMin + nums[i], nums[i]);
            minVal = Math.min(minVal, currMin);
        }
        
        if (maxVal > 0) {
            return Math.max(maxVal, total - minVal);
        }        
        
        return maxVal;
    }
}