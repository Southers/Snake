#pragma once
#include "Useful.h"

//define keys
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//declarations
bool gameOver;
int width = 50;
const int height = 20;
int x;
int y;
int foodX, foodY, score;
int tailX[100], tailY[100];
int nTail;
int speed = 30;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup();
void Draw();
void Input();
void Logic();


