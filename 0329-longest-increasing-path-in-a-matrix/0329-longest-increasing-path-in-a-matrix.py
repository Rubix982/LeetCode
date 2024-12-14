class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
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
