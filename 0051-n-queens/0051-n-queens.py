class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["."] * n for _ in range(n)]
        results = []
        self.placeQueen(n, 0, board, results)
        return [["".join(row) for row in result] for result in results]

    def placeQueen(self, n: int, row: int, board: List[List[str]], results: List[List[List[str]]]):
        if row == n:
            results.append([row[:] for row in board])
            return board

        for col in range(n):
            if self.canPlaceQueen(board, row, col, n):
                board[row][col] = "Q"
                self.placeQueen(n, row + 1, board, results)
                board[row][col] = "."


    def canPlaceQueen(self, board: List[List[str]], row: int, col: int, n: int) -> bool:
        # Check column
        for i in range(row):
            if board[i][col] == "Q":
                return False

        # Check upper-left diagonal
        for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
            if board[i][j] == "Q":
                return False

        # Check upper-right diagonal
        for i, j in zip(range(row - 1, -1, -1), range(col + 1, n)):
            if board[i][j] == "Q":
                return False

        return True
