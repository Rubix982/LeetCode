class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        /* How to optimize this into space complexity of O(1)? */
        
        Stack<Character> s1 = new Stack<Character>();
        Stack<Character> s2 = new Stack<Character>();
        for(char ch : s.toCharArray()){
            if(ch == '#'){
                if(!s1.isEmpty())
                    s1.pop();
                continue;
            }
            s1.push(ch);
        }
        for(char ch : t.toCharArray()){
            if(ch == '#'){
                if(!s2.isEmpty())
                    s2.pop();
                continue;
            }
            s2.push(ch);
        }
        String res1 = "";
        String res2 = "";
        while(!s1.isEmpty())
            res1 += s1.pop();
        while(!s2.isEmpty())
            res2 += s2.pop();
        return res1.equals(res2);
    }
}