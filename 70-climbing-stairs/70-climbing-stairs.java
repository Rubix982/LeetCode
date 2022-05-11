class Solution {
    
    int[] arr = new int[46];
    
    public int climbStairs(int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 0;
        }

        if (arr[n] == 0) {
            arr[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        
        return arr[n];
    }
}