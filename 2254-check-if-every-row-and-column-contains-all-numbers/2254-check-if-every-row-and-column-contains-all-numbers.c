bool checkValid(int** board, int boardSize, int* boardColSize) {
    int expectedTotalRowSum = (boardSize * (boardSize + 1)) / 2;
    int colSum = 0;
    int rowSum = 0;
    int i = 0;
    int j = 0;
    int i_k = 0;
    int j_k = 0;

    for (i = 0; i < boardSize; i++) {
        rowSum = 0;
        for (j = 0; j < boardSize; j++) {
            for (i_k = 0; i_k < boardSize; i_k++) {
                if (i == i_k) {
                    continue;
                }

                if (board[i][j] == board[i_k][j]) {
                    return false;
                }
            }

            rowSum += board[i][j];
        }

        if (rowSum != expectedTotalRowSum) {
            return false;
        }
    }

    for (i = 0; i < boardSize; i++) {
        colSum = 0;
        for (j = 0; j < boardSize; j++) {
            for (j_k = 0; j_k < boardSize; j_k++) {
                if (j == j_k) {
                    continue;
                }

                if (board[i][j] == board[i][j_k]) {
                    return false;
                }
            }

            colSum += board[j][i];
        }

        if (colSum != expectedTotalRowSum) {
            return false;
        }
    }

    return true;
}