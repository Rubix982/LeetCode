class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> ans;

    for (int s : spells) {
        long long required = (success + s - 1) / s; // ceil division
        int idx = lower_bound(potions.begin(), potions.end(), required) - potions.begin();
        ans.push_back(m - idx);
    }

    return ans;
    }
};