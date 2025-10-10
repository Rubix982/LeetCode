class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int localMax = 0;
                // check all 9 elements in the 3x3 submatrix
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        localMax = max(localMax, grid[x][y]);
                    }
                }
                ans[i][j] = localMax;
            }
        }

        return ans;
    }
};