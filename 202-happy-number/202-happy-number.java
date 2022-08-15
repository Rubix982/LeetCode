import java.lang.*;

class Solution {
    public boolean isHappy(int n) {
        if (n <= 0) {
            return false;
        }
        
        int sum = 0;

        while (n >= 10) {            
            for (sum = 0; n > 0; n /= 10) {
                sum += (n % 10) * (n % 10);
            }
            n = sum;
        }
        
        return n == 1 || n == 7;
    }
}