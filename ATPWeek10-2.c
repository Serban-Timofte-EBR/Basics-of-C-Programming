//problema reginelor - nu se pot ataca pe linii, coloane si diagonale

#include <stdio.h>

#define N 5

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    // Verificăm rândul în stânga
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    // Verificăm diagonala superioară stângă
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Verificăm diagonala inferioară stângă
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1; // Dacă nu există conflicte, poziția este sigură
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col == N) {
        // Am plasat toate reginele
        printBoard(board);
        return 1;
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Plasăm regina pe poziția (i, col)
            board[i][col] = 1;

            // Apelăm recursiv pentru a plasa restul reginelor
            res += solveNQueensUtil(board, col + 1);

            // Dacă adăugarea reginei nu duce la o soluție validă, o eliminăm
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0) == 0) {
        printf("Nu există soluție pentru această dimensiune a tablei de șah.\n");
    }
}

int main() {
    solveNQueens();
    return 0;
}
