#pragma once

#include <curses.h> //include library for terminal graphics

#define UP KEY_UP
#define DOWN KEY_DOWN
#define LEFT KEY_LEFT
#define RIGHT KEY_RIGHT
#define EXIT_GAME 'q'
typedef int graphics_input; //the type of the graphics input


#define GAME_TOP_WALL_Y 1
#define GAME_BOTTOM_WALL_Y (LINES - 4)
#define GAME_LEFT_WALL_X 1
#define GAME_RIGHT_WALL_X (COLS - 2)

void initializeGraphics(char* gameName);
void endGraphics(void);
void refreshScreen(void);
void printChar(int y, int x, graphics_input img);
void printMsg(int y, int x, char *str);
char readChar(int y, int x);
int readInpt();

void advanceDifficulty(void);