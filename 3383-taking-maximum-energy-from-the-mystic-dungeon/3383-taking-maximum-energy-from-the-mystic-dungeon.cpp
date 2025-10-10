class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        // Process from the back
        for (int i = n - k - 1; i >= 0; --i) {
            energy[i] += energy[i + k];
        }

        // The max value in energy now represents the best starting point
        return *max_element(energy.begin(), energy.end());
    }
};