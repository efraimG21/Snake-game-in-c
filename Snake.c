#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <windows.graphics.h>


#define SIZE 20

typedef struct Tail {
	int xLine;
	int yLine;
}Tail_t;

typedef struct Snake {
	Tail_t* tail;
	int length;
}Snake_t;

Snake_t* Resat(char board[SIZE][SIZE]);
void     PrintBoard(char board[SIZE][SIZE]);
void     Move(char board[SIZE][SIZE], Snake_t* snake);
void     Apple(char board[SIZE][SIZE]);
int      MoveLogic(char board[SIZE][SIZE], int move, int* timer, Snake_t* snake);
void     TailLogic(char board[SIZE][SIZE], Snake_t* snake);

int start()
{
	char board[SIZE][SIZE]; 
	Snake_t* snake = Resat(board);

	if (!snake)
	{
		printf("Try again later");
		return 0;
	}
	Move(board, snake);
	return 0;
}

Snake_t* Resat(char board[SIZE][SIZE])
{

	Snake_t* snake;

	snake = (Snake_t*)malloc(sizeof(Snake_t));
	if (!snake)
	{
		return NULL;
	}
	snake->tail = (int*)calloc((SIZE * SIZE - 1), sizeof(int));
	if (!snake->tail)
	{
		free(snake);
		return NULL;
	}
	snake->length = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			*(*(board + i) + j) = ' ';
		}
	}
	*(*(board + 17) + 18) = '*';
	snake->tail[0].xLine = 17;
	snake->tail[0].yLine = 18;
	Apple(board);
	return snake;
}

void PrintBoard(char board[SIZE][SIZE])
{
	system("cls");
	printf("up = 1, down = 2\nleft = 3, right = 4\n");
	printf(" ");
	for (int i = 1; i <= SIZE; ++i)
	{
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < SIZE; ++i)
	{
		printf("#");
		for (int j = 0; j < SIZE; ++j)
		{
			printf("%c", board[i][j]);
		}
		printf("#\n");
	}
	printf(" ");
	for (int i = 1; i <= SIZE; ++i)
	{
		printf("#");
	}
	printf("\n");
}

void Move(char board[SIZE][SIZE], Snake_t* snake)
{
	int move = 1, exit = 1, timer = 700;

	while (exit)
	{
		PrintBoard(board);
		Sleep(timer);
		if (_kbhit())
		{
			switch (getch())
			{
			case '1':
				move = 1;
				break;
			case '2':
				move = 2;
				break;
			case '3':
				move = 3;
				break;
			case '4':
				move = 4;
				break;
			default:
				printf("Wrong input");
				break;
			}
		}
		if (!MoveLogic(board, move, &timer, snake))
		{
			exit = 0;
		}
	}
	printf("you lose\n");
	free(snake->tail);
	free(snake);
}

int MoveLogic(char board[SIZE][SIZE], int move, int* timer, Snake_t* snake)
{
	int xMovement = 0, yMovement = 0;
	size_t xLine = snake->tail[0].xLine, yLine = snake->tail[0].yLine;

	switch (move)
	{
	case 1:
		if (snake->tail[0].xLine == 0 || board[snake->tail[0].xLine - 1][snake->tail[0].yLine] == '*')
		{
			return 0;
		}
		xMovement = (-1);
		break;
	case 2:
		if (snake->tail[0].xLine == (SIZE - 1) || board[snake->tail[0].xLine + 1][snake->tail[0].yLine] == '*')
		{
			return 0;
		}
		xMovement = 1;
		break;
	case 3:
		if (snake->tail[0].yLine == 0 || board[snake->tail[0].xLine][snake->tail[0].yLine - 1] == '*')
		{
			return 0;
		}
		yMovement = (-1);
		break;
	case 4:
		if (snake->tail[0].yLine == (SIZE - 1) || board[snake->tail[0].xLine][snake->tail[0].yLine + 1] == '*')
		{
			return 0;
		}
		yMovement = 1;
		break;
	}
	if (board[(snake->tail[0].xLine + (xMovement))][(snake->tail[0].yLine + (yMovement))] == ' ')
	{
		TailLogic(board, snake);
		board[(snake->tail[0].xLine += (xMovement))][(snake->tail[0].yLine += (yMovement))] = '*';
	}
	else if (board[(snake->tail[0].xLine + (xMovement))][(snake->tail[0].yLine + (yMovement))] == '@')
	{
		snake->length += 1;
		if (snake->length >= (SIZE * SIZE - 40))
		{
			printf("\n\nYOU WIN\n\n");
			exit;
		}
		TailLogic(board, snake);
		board[(snake->tail[0].xLine += (xMovement))][(snake->tail[0].yLine += (yMovement))] = '*';
		Apple(board);
		*timer -= 10;
	}
	return 1;
}

void TailLogic(char board[SIZE][SIZE], Snake_t* snake)
{
	int length = snake->length;

	board[snake->tail[length].xLine][snake->tail[length].yLine] = ' ';
	for (int i = length; i > 0; --i)
	{
		snake->tail[i].xLine = snake->tail[i - 1].xLine;
		snake->tail[i].yLine = snake->tail[i - 1].yLine;
	}
}

void Apple(char board[SIZE][SIZE])
{
	int row, col, exit = 1;

	srand(time(NULL));
	while (exit)
	{
		row = rand() % SIZE;
		col = rand() % SIZE;
		if (board[row][col] == ' ')
		{
			board[row][col] = '@';
			return;
		}
	}
}
