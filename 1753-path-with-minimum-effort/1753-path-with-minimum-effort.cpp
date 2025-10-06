class Solution {
public:
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // (effort_so_far, row, col)
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<>> pq;

    pq.push({0, 0, 0});
    effort[0][0] = 0;

    while (!pq.empty()) {
        auto [currEffort, r, c] = pq.top();
        pq.pop();

        if (r == n-1 && c == m-1) return currEffort;
        if (currEffort > effort[r][c]) continue;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

            int diff = abs(heights[nr][nc] - heights[r][c]);
            int newEffort = max(currEffort, diff);

            if (newEffort < effort[nr][nc]) {
                effort[nr][nc] = newEffort;
                pq.push({newEffort, nr, nc});
            }
        }
    }
    return 0; // should never hit
}
};