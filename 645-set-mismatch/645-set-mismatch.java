class Solution {
    public int[] findErrorNums(int[] nums) {
        
        int[] result = new int[2];
        
        boolean[] numBool = new boolean[nums.length];
        int duplicate = -1;
        int toReplaceWith = -1;
        
        for (int i = 0; i < nums.length; i++) {
            numBool[i] = false;
        }
        
        for (int i = 0 ; i<nums.length; i++) {
            if (numBool[nums[i] - 1] == false) {
                numBool[nums[i] - 1] = true;
            } else {
                duplicate = nums[i];
            }
        }
        
        for (int i = 0; i < nums.length; i++) {
            System.out.println(numBool[i]);
        }
        
        
        for (int i = 0 ; i<nums.length; i++) {
            if (numBool[i] == false) {
                toReplaceWith = i;
            }
        }
        
        // System.out.println(toReplaceWith + 1);     
        // System.out.println(duplicate + 1);        
        
        return new int[]{duplicate, toReplaceWith + 1};
    }
}