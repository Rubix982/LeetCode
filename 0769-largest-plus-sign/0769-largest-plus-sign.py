class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        mines_set = set(map(tuple, mines))
        dp = [[n] * n for _ in range(n)]  # Initialize DP grid with maximum possible arm length
        
        # Fill DP for all directions
        for i in range(n):
            # Left and Right pass
            left = right = 0
            for j in range(n):
                # Leftward
                left = 0 if (i, j) in mines_set else left + 1
                dp[i][j] = min(dp[i][j], left)
                
                # Rightward
                right = 0 if (i, n - 1 - j) in mines_set else right + 1
                dp[i][n - 1 - j] = min(dp[i][n - 1 - j], right)

        for j in range(n):
            # Up and Down pass
            up = down = 0
            for i in range(n):
                # Upward
                up = 0 if (i, j) in mines_set else up + 1
                dp[i][j] = min(dp[i][j], up)
                
                # Downward
                down = 0 if (n - 1 - i, j) in mines_set else down + 1
                dp[n - 1 - i][j] = min(dp[n - 1 - i][j], down)
        
        # The largest plus sign is determined by the maximum value in the DP table
        return max(max(row) for row in dp)
