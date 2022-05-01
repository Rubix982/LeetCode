class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        
        if (nums == null || len <= 1) {
            return 0;
        }
        
        int[] minJump = new int[len];
        
        minJump[len - 1] = 0;
        
        for (int i = len - 2; i >= 0; i--) {
            if (i + nums[i] >= len - 1) {
                minJump[i] = 1;
            }
            else if (nums[i] > 0 ) {
                // cannot directly reach from pos i
                int minFromJ = Integer.MAX_VALUE;
                
                for (int j = i + 1; j <= i + nums[i]; j++) {
                    if (minJump[j] > 0) {
                        minFromJ = Math.min(minFromJ, minJump[j]);
                    }
                }
                
                minJump[i] = minFromJ < Integer.MAX_VALUE ? (minFromJ + 1) : 0;
            }
        }
        
        return minJump[0];
    }
}