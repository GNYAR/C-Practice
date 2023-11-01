#include <iostream>
#define SIZE 10

using namespace std;

typedef struct
{
	int row, col;
} position;

typedef struct
{
	position pos;
	int dir;
} element;

void push(element stack[], int &top, element x)
{
	stack[++top] = x;
}

element pop(element stack[], int &top)
{
	return stack[top--];
}

position START = {8, 8};
position EXIT = {1, 1};
position MOVES[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void findPath(int maze[SIZE][SIZE], element stack[], int &top)
{
	bool marks[SIZE][SIZE] = {false};
	element x = {START, 0};
	push(stack, top, x);
	while (top > -1)
	{
		x = pop(stack, top);
		while (x.dir < 4)
		{
			int nextRow = x.pos.row + MOVES[x.dir].row;
			int nextCol = x.pos.col + MOVES[x.dir].col;
			if (nextRow == EXIT.row && nextCol == EXIT.col)
			{
				push(stack, top, x);
				return;
			}
			x.dir++;
			if (!maze[nextRow][nextCol] && !marks[nextRow][nextCol])
			{
				push(stack, top, x);
				marks[x.pos.row][x.pos.col] = true;
				x = {{nextRow, nextCol}, 0};
			}
		}
	}
}

int main()
{
	int maze[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			cin >> maze[i][j];
	element path[SIZE * SIZE];
	int top = -1;
	findPath(maze, path, top);
	if (top == -1)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		while (top > -1)
		{
			element x = pop(path, top);
			maze[x.pos.row][x.pos.col] = 2;
		}

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
			{
				if (i == START.row && j == START.col)
					cout << 'S';
				else if (i == EXIT.row && j == EXIT.col)
					cout << 'X';
				else if (maze[i][j] == 2)
					cout << 'G';
				else
					cout << maze[i][j];
				if (j < SIZE - 1)
					cout << ' ';
				else
					cout << endl;
			}
	}
	return 0;
}
