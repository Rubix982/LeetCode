class Solution {
    
    public long sumArray(int[] nums) {
            long sum = 0;
            for (int i = 0; i < nums.length; i++) {
                sum += nums[i];
            }
            return sum;
    }
    
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int totalSum = 0 ;
        int minSubarray = 0;
        
        for (int i = 0, currSum = 0; i < n; i++) {
            totalSum += cardPoints[i];
            currSum += cardPoints[i];
            
            if ( i < n - k ) {
                minSubarray += cardPoints[i];
            } else {
                currSum -= cardPoints[i - (n-k)];
                minSubarray = Math.min(minSubarray, currSum);
            }
        }
        
        return totalSum - minSubarray;
    }
}