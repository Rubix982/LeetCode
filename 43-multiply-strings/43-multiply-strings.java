class Solution {
    public String multiply(String num1, String num2) {
        int m = num1.length(), n = num2.length();
        int[] res = new int[m + n];
        
        //calculate from low to high
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--) {
                //p2 is the lower position
                //n1[i] * n2[j] need to be put into res[i+j] and res[i+j+1]
                int hi = i + j, lo = i + j + 1;
                //new value should be added into cooresponding position of previous computation
                int mul = getDigit(num1, i) * getDigit(num2, j) + res[lo];
                res[hi] += mul / 10;
                res[lo] = mul % 10;
            }
        }
        //deal with leading 0s
        int i = 0;
        while(i < m + n && res[i] == 0) {
            i++;
        }
        
        StringBuilder sb = new StringBuilder();
        for(; i < m + n; i++) {
            sb.append(res[i]);
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
    
    private int getDigit(String s, int i) {
        return s.charAt(i) - '0';
    }
}