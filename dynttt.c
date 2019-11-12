#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Print the board on the screen.
void printBoard(char** board) {
    int i, j;

    printf("  ");
    for (i = 1; i <= 3; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < 3; ++i) {
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Checks whether a particular space has already been filled��
// If the space is filled it returns a boolean value of true, otherwise false.
bool isFilled(char** board, int row, int col) {
    return board[row][col] != 'e';
}

// Prompt the user for their next move.
void move(char** board, char player) {
    int row, col;
    while (true) {
        printf(
            "Player %c: please enter the coordinates of your move (row col):",
            player);
        row = col = -1;
        scanf("%d%d", &row, &col);
        --row;
        --col;
        if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
            if (isFilled(board, row, col)) {
                printf("Invalid move! That cell is already taken!\n\n");
            } else {
                board[row][col] = player;
                printBoard(board);
                printf("\n");
                break;
            }
        } else {
            printf("Invalid move! That cell does not exist!\n");
        }
    }
}

// Detect whether it is game over.
bool isGameOver(char** board, int nmoves) {
    int i;

    // check rows and cols
    for (i = 0; i < 3; ++i) {
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') ||
            (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')) {
            printf("Player X has won!\n");
            return true;
        } else if ((board[i][0] == 'O' && board[i][1] == 'O' &&
                    board[i][2] == 'O') ||
                   (board[0][i] == 'O' && board[1][i] == 'O' &&
                    board[2][i] == 'O')) {
            printf("Player Y has won!\n");
            return true;
        }
    }

    // check cross
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        printf("Player X has won!\n");
        return true;
    } else if ((board[0][0] == 'O' && board[1][1] == 'O' &&
                board[2][2] == 'O') ||
               (board[0][2] == 'O' && board[1][1] == 'O' &&
                board[2][0] == 'O')) {
        printf("Player Y has won!\n");
        return true;
    }

    if (nmoves == 9) {
        printf("You get a draw!\n");
        return true;
    }

    return false;
}

int main() {
    int i, j, nmoves;
    bool gameOver;
    char** board;
    char players[2] = {'X', 'O'};

    board = (char**)malloc(sizeof(char*) * 3);
    for (i = 0; i < 3; ++i) {
        board[i] = (char*)malloc(sizeof(char) * 3);
    }

    while (true) {
        gameOver = false;
        // init the board
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; j++) {
                board[i][j] = 'e';
            }
        }

        printBoard(board);

        // game start
        nmoves = 0;
        while (true) {
            for (i = 0; i < 2; ++i) {
                move(board, players[i]);
                ++nmoves;
                if (isGameOver(board, nmoves)) {
                    gameOver = true;
                    break;
                }
            }
            if (gameOver) {
                break;
            }
        }
        printf("\n*********************************\n");
    }

    for (i = 0; i < 3; ++i) {
        free(board[i]);
    }
    free(board);

    return 0;
}