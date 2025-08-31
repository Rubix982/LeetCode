#include <stdbool.h>

bool solve(char** board, bool rowUsed[9][9], bool colUsed[9][9], bool blockUsed[9][9], int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solve(board, rowUsed, colUsed, blockUsed, row + 1, 0);
    if (board[row][col] != '.') return solve(board, rowUsed, colUsed, blockUsed, row, col + 1);

    for (char c = '1'; c <= '9'; c++) {
        int d = c - '1';
        int block = (row/3)*3 + (col/3);
        if (!rowUsed[row][d] && !colUsed[col][d] && !blockUsed[block][d]) {
            board[row][col] = c;
            rowUsed[row][d] = colUsed[col][d] = blockUsed[block][d] = true;

            if (solve(board, rowUsed, colUsed, blockUsed, row, col + 1))
                return true;

            board[row][col] = '.'; // backtrack
            rowUsed[row][d] = colUsed[col][d] = blockUsed[block][d] = false;
        }
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    bool rowUsed[9][9] = {false};
    bool colUsed[9][9] = {false};
    bool blockUsed[9][9] = {false};

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] != '.') {
                int d = board[i][j] - '1';
                rowUsed[i][d] = true;
                colUsed[j][d] = true;
                blockUsed[(i/3)*3 + (j/3)][d] = true;
            }

    solve(board, rowUsed, colUsed, blockUsed, 0, 0);
}
