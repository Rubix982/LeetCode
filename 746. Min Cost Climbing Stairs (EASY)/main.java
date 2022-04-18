class Solution {

    int[] dp = new int[1001];

    public int solve(int[] cost, int n) {
        if (n <= 1) {
            return 0;
        }

        if (dp[n] == 0) {
            dp[n] = Math.min(solve(cost, n - 1) + cost[n - 1], solve(cost, n - 2) + cost[n - 2]);
        }

        return dp[n];
    }

    public int minCostClimbingStairs(int[] cost) {
        return solve(cost, cost.length);
    }
}