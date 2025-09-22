class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[101] = {0};
        int maxFreqCount = 0;
        for (auto &x: nums) {
            arr[x]++;
            maxFreqCount = max(maxFreqCount, arr[x]);
        }

        int totalCount = 0;
        for (int i = 0; i <= 100; i++) if (arr[i] == maxFreqCount) totalCount += maxFreqCount;

        return totalCount;
    }
};