class Solution {
public:
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // Min-heap: stores (time, x, y)
    priority_queue<
        tuple<int,int,int>, 
        vector<tuple<int,int,int>>, 
        greater<>
    > pq;

    pq.push({grid[0][0], 0, 0});
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int ans = 0;
    while (!pq.empty()) {
        auto [t, x, y] = pq.top();
        pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        ans = max(ans, t);
        if (x == n-1 && y == n-1) return ans;

        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                pq.push({grid[nx][ny], nx, ny});
            }
        }
    }

    return ans; // should never reach here
}
};