bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int startingIIndex = 0;
    int endingIIndex = 0;
    int startingJIndex = 0;
    int endingJIndex = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            char currBoardValue = board[i][j];
            if (currBoardValue == '.') {
                continue;
            } // It is empty, we don't need to check

            // We want to first look horizontally
            for (int horizontal = 0; horizontal < boardSize; horizontal++) {
                // Skip the element we are looking at itself
                if (horizontal == j) {
                    continue;
                }

                if (board[i][horizontal] == currBoardValue) {
                    return false;
                }
            }

            // Secondly, look vertically
            for (int vertical = 0; vertical < boardSize; vertical++) {
                // Skip the element we are looking at itself
                if (vertical == i) {
                    continue;
                }

                if (board[vertical][j] == currBoardValue) {
                    return false;
                }
            }

            if (i >= 0 && i <= 2) {
                endingIIndex = 0;
                endingIIndex = 2;
            } else if (i >= 3 && i <= 5) {
                startingIIndex = 3;
                endingIIndex = 5;
            } else if (i >= 6) {
                startingIIndex = 6;
                endingIIndex = 8;
            }

            // TOP 3 blocks
            // search grid for [0][0], [0][1], [0][2], [1][0], [1][1], [1][2], [2][0], [2][1], [2][2]
            // search grid for [0][3], [0][4], [0][5], [1][3], [1][4], [1][5], [2][3], [2][4], [2][5]
            // search grid for [0][6], [0][7], [0][8], [1][6], [1][7], [1][8], [2][6], [2][7], [2][8]

            // MIDDLE 3 blocks
            // search grid for [3][0], [3][1], [3][2], [4][0], [4][1], [4][2], [5][0], [5][1], [5][2]
            // search grid for [3][3], [3][4], [3][5], [4][3], [4][4], [4][5], [5][3], [5][4], [5][5]
            // search grid for [3][6], [3][7], [3][8], [4][6], [4][7], [4][8], [5][6], [5][7], [5][8]

            // BOTTOM 3 blocks
            // search grid for [6][0], [6][1], [6][2], [7][0], [8][1], [8][2], [9][0], [9][1], [9][2]
            // search grid for [6][3], [6][4], [6][5], [7][3], [8][4], [8][5], [9][3], [9][4], [9][5]
            // search grid for [6][6], [6][7], [6][8], [7][6], [8][7], [8][8], [9][6], [9][7], [9][8]
            for (int i_k = startingIIndex; i_k <= endingIIndex; i_k++) {
                if (j >= 0 && j <= 2) {
                    startingJIndex = 0;
                    endingJIndex = 2;
                } else if (j >= 3 && j <= 5) {
                    startingJIndex = 3;
                    endingJIndex = 5;
                } else if (j >= 6) {
                    startingJIndex = 6;
                    endingJIndex = 8;
                }

                if (j >= startingJIndex && j <= endingJIndex) {
                    for (int j_k = startingJIndex; j_k <= endingJIndex; j_k++) {
                        if (i_k == i && j_k == j) {
                            continue;
                        }

                        if (currBoardValue == board[i_k][j_k]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}