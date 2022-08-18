class Solution {
    
    public String longestCommonPrefix(String[] strs) {
   
        if (strs.length == 0) {
            return "";
        }
        
        if (strs.length == 1) {
            return strs[0];
        }

        for (int i = 0; i < strs.length; i++) {    
            if (strs[i].length() == 0) {
                return "";
            }
        }
        
        int endingIndex = 0;
        boolean hasPrefixMaxLengthReached = false;
        
        while (true) {

            for (int i = 0; i < strs.length; i++) {
                if (endingIndex > strs[i].length() - 1) {
                    hasPrefixMaxLengthReached = true;
                    break;
                }
            }
            
            if (hasPrefixMaxLengthReached) {
                break;
            }
            
            char posChar = strs[0].charAt(endingIndex);
            boolean prefixEndReached = false;
            
            for (int i = 1; i < strs.length; i++) {
                if (posChar != strs[i].charAt(endingIndex)) {
                    prefixEndReached = true;
                    break;
                }
            }
            
            if (prefixEndReached) {
                break;
            }
            
            endingIndex += 1;
        }
        
        return strs[0].substring(0, endingIndex);
    }
}