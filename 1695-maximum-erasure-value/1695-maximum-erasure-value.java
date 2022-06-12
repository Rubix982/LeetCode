class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int maxSum = 0, currSum = 0;
        Set<Integer> set = new HashSet<Integer> ();
        
        for (int l = 0, r = 0; r < nums.length; r++) {
            while (!set.add(nums[r])) {
                currSum -= nums[l];
                set.remove(nums[l++]);
            }
            currSum += nums[r];
            maxSum = Math.max(maxSum, currSum);             
        }
        
        return maxSum;
    }
}