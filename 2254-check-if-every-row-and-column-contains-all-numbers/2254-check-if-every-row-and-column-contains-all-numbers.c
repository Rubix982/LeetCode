bool checkValid(int** board, int boardSize, int* boardColSize) {
    int i = 0;
    int j = 0;
    int i_k = 0;
    int j_k = 0;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            for (i_k = 0; i_k < boardSize; i_k++) {
                if (i == i_k) {
                    continue;
                }

                if (board[i][j] == board[i_k][j]) {
                    return false;
                }
            }

            for (j_k = 0; j_k < boardSize; j_k++) {
                if (j == j_k) {
                    continue;
                }

                if (board[i][j] == board[i][j_k]) {
                    return false;
                }
            }
        }
    }

    return true;
}