class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Run DFS from edges
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);       // Pacific left
            dfs(heights, atlantic, i, n - 1); // Atlantic right
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);       // Pacific top
            dfs(heights, atlantic, m - 1, j);  // Atlantic bottom
        }

        // Collect result
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size(), n = heights[0].size();
        if (visited[i][j]) return;
        visited[i][j] = true;

        // directions: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
    }
};
