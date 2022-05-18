class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> jm=new ArrayList<>();

        int cr=Integer.MAX_VALUE;
    
        for(int I=0; I<nums.length-2; I++) {
            int x=nums[I];
            
            if  (cr!=x) {
                cr=x;
            }   
            else { 
                continue;
            }
        
            int pp=I+1;
            int pe=nums.length-1;
        
            while(pp<pe) {
                if  (x+nums[pp]+nums[pe]==0)  {
            
                    jm.add(Arrays.asList(x, nums[pp], nums[pe]));
                
                    while (pp<pe&&nums[pp]==nums[pp+1]) {
                        pp++;
                    }

                    while (pp < pe && nums[pe] == nums[pp-1]) {
                        pe--;
                    }

                    pp++;
                    pe--;
                }
                else if (x+nums[pp]+nums[pe]<0) {
                    pp++;
                }
                else {
                    pe--;
                }
        }
    }

        return jm;
    }
}