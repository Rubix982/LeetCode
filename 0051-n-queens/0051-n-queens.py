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
    
        return board

    def canPlaceQueen(self, board, row, col, n) -> bool:
        # Check for any queens in the same column
        for i in range(n):
            if board[i][col] == "Q":
                return False

        # Check for any queens in the same row
        for j in range(n):
            if board[row][j] == "Q":
                return False

        # Check for queens in all diagonals
        for i in range(n):
            for j in range(n):
                if abs(row - i) == abs(col - j) and board[i][j] == "Q":
                    return False

        return True