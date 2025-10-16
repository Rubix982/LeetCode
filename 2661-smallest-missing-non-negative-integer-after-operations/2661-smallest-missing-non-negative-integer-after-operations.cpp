class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> remainderCounter;
        for (int num : nums) remainderCounter[((num % value) + value) % value]++;

        int mex = 0;
        while (true) {
            int r = mex % value;
            if (remainderCounter[r] > 0) {
                remainderCounter[r]--;
                mex++;
            } else return mex;
        }
    }
};