class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squaredVals;
        squaredVals.reserve(n);

        // find first non-negative index
        int firstPosIdx = 0;
        while (firstPosIdx < n && nums[firstPosIdx] < 0) firstPosIdx++;

        int negIdx = firstPosIdx - 1; // last negative
        int posIdx = firstPosIdx;     // first non-negative

        // merge like merge-sort
        while (negIdx >= 0 && posIdx < n) {
            if (abs(nums[negIdx]) < nums[posIdx]) {
                squaredVals.push_back(nums[negIdx] * nums[negIdx]);
                negIdx--;
            } else {
                squaredVals.push_back(nums[posIdx] * nums[posIdx]);
                posIdx++;
            }
        }

        // flush remaining negatives
        while (negIdx >= 0) {
            squaredVals.push_back(nums[negIdx] * nums[negIdx]);
            negIdx--;
        }

        // flush remaining positives
        while (posIdx < n) {
            squaredVals.push_back(nums[posIdx] * nums[posIdx]);
            posIdx++;
        }

        return squaredVals;
    }
};
