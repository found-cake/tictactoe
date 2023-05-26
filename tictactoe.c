#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 3

void initBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = ' ';
		}
	}
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("\n+---+---+---+\n");
		printf("| %c | %c | %c |", board[i][0], board[i][1], board[i][2]);
	}
	printf("\n+---+---+---+\n\n");
}

int checkWin(char board[SIZE][SIZE], char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }

    return 0;
}

int isBoardFull(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
	char tic[SIZE][SIZE];
	char current = 'X';
    int x, y;
	initBoard(tic);
	while (1) {
        printBoard(tic);

        printf("'%c' Player: ", current);
        scanf(" %d %d", &x, &y);

        if (x < 1 || y < 1 || x > SIZE || y > SIZE || tic[y - 1][x - 1] != ' ') {
            printf("잘못된 위치! 다시 입력해주세요.");
            continue;
        }
        tic[y - 1][x - 1] = current;
        if (checkWin(tic, current)) {
            printf("'%c' Player 승리!!!", current);
            break;
        }
        if (isBoardFull(tic)) {
            printf("무승부!");
            break;
        }
        current = current == 'X' ? 'O' : 'X';
	}

	return 0;
}
