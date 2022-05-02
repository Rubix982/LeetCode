import java.util.Arrays;
import java.util.HashMap;

class Solution {
    
    public int setValueToStartWith(int[] nums, boolean[] numBool, int valueToStartWith, int totalSum) {                
        int localSum = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == valueToStartWith && numBool[i] == true) {
                localSum += valueToStartWith;
                numBool[i] = false;
            } else if (nums[i] == valueToStartWith - 1 || nums[i] == valueToStartWith + 1) {    
                numBool[i] = false;
            }
        }
        
        int recursiveMax = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (numBool[i] == true) {
                recursiveMax = Math.max(totalSum + localSum, setValueToStartWith(nums, numBool, nums[i], totalSum));
            }
        }

        return recursiveMax;
    }
    
    public int deleteAndEarn(int[] nums) {
       
//         HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        
//         for (int i = 0 ; i < nums.length ; i++) {
//             if (!hm.containsKey(nums[i])) {
//                 hm.put(nums[i], 1);
//             }
//         }
        
//         int max = 0;
        
//         for (Integer i : hm.keySet()) {
//             boolean[] numBool = new boolean[nums.length];        
//             for (int j = 0; j < nums.length; j++) {
//                 numBool[j] = true;
//             }            
//             max = Math.max(max, setValueToStartWith(nums, numBool, i, 0));
//         }
        
//         return max;
        
        int[] sum = new int[10001];
        
        for (int i : nums) {
            sum[i] += i;
        }
        
        for (int i = 2; i < 10001; i++) {
            sum[i] = Math.max(sum[i-1], sum[i-2] + sum[i]);
        }
        
        return sum[10000];
    }
}