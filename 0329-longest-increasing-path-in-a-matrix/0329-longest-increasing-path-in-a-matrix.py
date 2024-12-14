from typing import List

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        rows, cols = len(matrix), len(matrix[0])
        memo = [[-1] * cols for _ in range(rows)]  # Memoization table
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(x: int, y: int, prev_val: int) -> int:
            # Base case: if out of bounds or decreasing value
            if x < 0 or x >= rows or y < 0 or y >= cols or matrix[x][y] <= prev_val:
                return 0

            if memo[x][y] != -1:
                return memo[x][y]

            max_length = 0
            for dx, dy in directions:
                max_length = max(max_length, dfs(x + dx, y + dy, matrix[x][y]))

            memo[x][y] = 1 + max_length
            return memo[x][y]

        longest_path = 0
        for i in range(rows):
            for j in range(cols):
                longest_path = max(longest_path, dfs(i, j, -1))

        return longest_path
