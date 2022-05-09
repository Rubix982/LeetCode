class Solution {
public int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<nums.length; i++){
            
            int compli = target-nums[i];
            
            if(!map.containsKey(compli)){
                map.put(nums[i], i);
            }
            
            else{
                return new int[] {i, map.get(compli)};
            }
            
        }
        
        throw new IllegalArgumentException("match not found");
        
    }
}