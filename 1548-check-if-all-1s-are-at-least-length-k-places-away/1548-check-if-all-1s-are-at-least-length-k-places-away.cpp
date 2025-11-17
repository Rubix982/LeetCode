class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int currentDistance = 0;
        bool seenFirstOne = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (seenFirstOne) currentDistance++;
                continue;
            }
            seenFirstOne = true;

            if (i > 0 && nums[i-1] == 1 && k != 0) {
                // curr value is 1, and last val is also 1 and k is not zero
                return false;
            }

            if (currentDistance == 0) {
                // prev val was 1
                continue;
            }

            if (currentDistance < k) {
                return false;
            }

            currentDistance = 0; // reset to 0
        }

        return true;
    }
};