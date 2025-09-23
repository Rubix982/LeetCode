class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string token1, token2;
        
        while (true) {
            // read next part or default to "0"
            if (!getline(ss1, token1, '.')) token1 = "0";
            if (!getline(ss2, token2, '.')) token2 = "0";
            
            // convert to int (handles leading zeros)
            int num1 = stoi(token1);
            int num2 = stoi(token2);
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            // both streams exhausted
            if (!ss1 && !ss2) break;
        }
        
        return 0;
    }
};