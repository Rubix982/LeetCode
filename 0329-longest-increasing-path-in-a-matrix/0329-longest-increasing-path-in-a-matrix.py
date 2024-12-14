class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        # Khans' Algothim is good approach is you want a lower memory footprint
        # but it is slow. Consider using the regular memoization technique for a better
        # runtime as a tradeoff
        # Khan's Algorithm Technique -> Runtime (229ms, Beats 18.26%), Memory (18.56 MB, Beats 72.76%)
        # Memoization Technique -> Runtime (171ms, Beats 51.07%), Memory (18.88 MB, Beats 67.81%)
        # return self.longestIncreasingPathKhanAlgorithm(matrix)
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

    def longestIncreasingPathKhanAlgorithm(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        rows, cols = len(matrix), len(matrix[0])
        in_degree = [[0] * cols for _ in range(rows)]
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def is_valid(x: int, y: int, i: int, j: int) -> bool:
            return 0 <= x < rows and 0 <= y < cols and matrix[x][y] > matrix[i][j]

        # Build in-degree graph
        for i in range(rows):
            for j in range(cols):
                for dx, dy in directions:
                    x, y = i + dx, j + dy
                    if is_valid(x, y, i, j):
                        in_degree[x][y] += 1

        # Initialize the queue with nodes having zero in-degree
        queue = deque((i, j) for i in range(rows) for j in range(cols) if in_degree[i][j] == 0)
        level = 0

        # Perform BFS for topological sorting
        while queue:
            for _ in range(len(queue)):
                i, j = queue.popleft()
                for dx, dy in directions:
                    x, y = i + dx, j + dy
                    if is_valid(x, y, i, j):
                        in_degree[x][y] -= 1
                        if in_degree[x][y] == 0:
                            queue.append((x, y))
            level += 1  # Increase the level after processing each layer

        return level
