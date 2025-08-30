bool checkValid(int** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            // We want to first look horizontally
            for (int horizontal = 0; horizontal < boardSize; horizontal++) {
                // Skip the element we are looking at itself
                if (horizontal == j) {
                    continue;
                }

                if (board[i][horizontal] == board[i][j]) {
                    return false;
                }
            }

            // Secondly, look vertically
            for (int vertical = 0; vertical < boardSize; vertical++) {
                // Skip the element we are looking at itself
                if (vertical == i) {
                    continue;
                }

                if (board[vertical][j] == board[i][j]) {
                    return false;
                }
            }
        }
    }

    return true;
}