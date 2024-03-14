#pragma once
#include "Main.h"

//setup function
void Setup()
{
	gameOver = false;
	dir = STOP;
	foodX = rand() % width;
	foodY = rand() % height;
	score = 0;
	speed = 30;
}

//draw visuals function
void Visuals()
{
	//ClearScreen;
	system("cls");

	for (int i = 0; i < width + 2; i++)
		cout << "x";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "x";
			if (i == y && j == x)
				cout << "O";
			else if (i == foodY && j == foodX)
				cout << "%";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "x";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "x";
	cout << endl;
	cout << endl;
	cout << "Score:" << score << endl;
	cout << endl;
	cout << "Use arrow keys to control the snake";
}

//input function
void PlayerInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_LEFT:
			dir = LEFT;
			break;
		case KEY_RIGHT:
			dir = RIGHT;
			break;
		case KEY_UP:
			dir = UP;
			break;
		case KEY_DOWN:
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

//main gamelogic function
void GameplayLogic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	//loop through the number of tails
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	//define direction based on input
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//if (x > width || x < 0 || y > height || y < 0) then gameOver = true; 
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	
	if (x == foodX && y == foodY)
	{
		score += 10;
		foodX = rand() % width;
		foodY = rand() % height;
		nTail++;
		speed /= 1.2;
	}
}

int main()
{
	ShowConsoleCursor(false);

	//run once to initialise and set variables
	Setup();			
	
	//while loop until gameover
	while (!gameOver)		
	{
		//draws the level out on screen
		Visuals();
		//takes the player input and maps a direction
		PlayerInput();
		//sets the tail logic and replaces food
		GameplayLogic();
		//set the speed of snake (and everything)
		Sleep(speed);			
	}

	cout << endl;
	cout << endl;
	
	cout << "Gameover!";
	cout << endl;

	system("pause");

	return 0;
}