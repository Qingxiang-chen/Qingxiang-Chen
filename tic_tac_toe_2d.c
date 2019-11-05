#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"     //set the game 3x3 board
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
 
 void menu()
{
	printf("*************************\n");
	printf("*****    1.play    ******\n");
	printf("*****    0.exit    ******\n");
	printf("*************************\n");
 
}
void game()
{
	int input = 1;
	char board[ROWS][COLS] = { 0 };
	init_board(board, ROWS, COLS);
	while (input)
	{
		menu();
		printf("play or exit:");
		scanf("%d", &input);
		if (input == 1)
		{
			init_board(board, ROWS, COLS);
			print_board(board, ROWS, COLS);
			play_game(board);
		}
 
	}
}
 
void ai_move(char board[ROWS][COLS])                  // AI 's move simple
{
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';  
			return;
		}
	}
 
}
void player_move(char board[ROWS][COLS])              // player's simple 
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("input location (rows then cols):");
		scanf("%d%d", &x, &y);
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = 'O';
			return;
		}
		else
		{
			printf("wrong number ");
		}
	}
 
}
 
char check_win(char board[ROWS][COLS])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
		{
			return 'p';
		}
	}
	for (i = 0; i < 3; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[1][i] != ' '))
		{
			return 'p';
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' '))
	{
		return 'p';
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return 'p';
	}
}
void init_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < ROWS; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		printf("---|---|---\n");
	}
}
void play_game(char board[ROWS][COLS])
{
	char ret;
	int count = 0;
	while (1)
	{
		if (count >= 9)                       // totaly blank is 9, if all blank set , get even 
		{
			printf("even ！\n");
			break;
		}
		player_move(board);
		count++;
		print_board(board, ROWS, COLS);
		if ((ret = check_win(board)) == 'p')
		{
			printf("you win!\n");
			break;
		}
		if (count >=  9)
		{
			printf("even!\n");
			break;
		}
		count++;
		printf("AI move:\n");
		ai_move(board);
		
		print_board(board, ROWS, COLS);
		if ((ret = check_win(board)) == 'p')
		{
			printf("you lose game!\n");
			break;
		}
		
	}
 
}



int main()
{
	game();
	return 0;
}

