class Solution {
    public int findUnsortedSubarray(int[] nums) {
            
//         boolean isSorted = true;
        
//         // base condition
//         for (int i = 0; i < nums.length - 1; i++) {
//             if (nums[i+1] < nums[i]) {
//                 isSorted = false;
//             }
//         }
        
//         if (isSorted) return 0;
        
//         int start = 0;
//         int end = nums.length - 1;
        
//         for (int i = 0; i < nums.length - 1; i++) {
//             if (nums[i+1] >= nums[i]) {
//                 start += 1;
//             } else {
//                 break;
//             }
//         }

//         for (int i = nums.length - 1; i > 0; i--) {
//             if (nums[i-1] <= nums[i]) {
//                 end -= 1;
//             } else {
//                 break;
//             }
//         }
        
//         return end - start + 1;
    
        int start = -1;
        int end = -1;
        int max = Integer.MIN_VALUE;

        for(int i=0; i<nums.length; i++){

            if(max>nums[i]){
                
                if(start == -1) { start = i-1; }

                while(start-1>=0 && nums[start-1]>nums[i])
                {
                    start--;
                }

                end = i+1;
            }
            else max = nums[i];
        }
        return end - start;      
        
    }
}