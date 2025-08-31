bool isValid(char** board, int row, int col, char c, int n) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == c) return false; // row check
        if (board[i][col] == c) return false; // column check

        int r = 3*(row/3) + i/3;
        int k = 3*(col/3) + i%3;

        if (board[r][k] == c) return false; // subgrid check
    }
    return true;
}

bool solve(char** board, int row, int col, int n) {
    if (row == n) return true; // solved all rows
    if (col == n) return solve(board, row + 1, 0, n); // next row
    if (board[row][col] != '.') return solve(board, row, col + 1, n);

    for (char c = '1'; c <= '9'; c++) {
        if (isValid(board, row, col, c, n)) {
            board[row][col] = c;
            if (solve(board, row, col + 1, n)) return true;
            board[row][col] = '.'; // backtrack
        }
    }
 
    return false; // no valid number
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board, 0, 0, boardSize);
}
