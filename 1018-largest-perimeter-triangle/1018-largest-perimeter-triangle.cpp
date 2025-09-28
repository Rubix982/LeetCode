class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); // sort descending
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if (b + c > a) // triangle inequality
                return a + b + c;
        }
        return 0;
    }
};