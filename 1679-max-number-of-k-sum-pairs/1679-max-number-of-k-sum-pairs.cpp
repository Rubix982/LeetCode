class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int ans = 0;

        for (auto elem:  nums) {
            int compliment = k - elem;
            
            if (freq[compliment] > 0) {
                ans++;
                freq[compliment]--;
            } else {
                freq[elem]++;
            }
        }
        
        return ans;
    }
};