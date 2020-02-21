#pragma once

#include <curses.h> //include library for terminal graphics

#define UP KEY_UP
#define DOWN KEY_DOWN
#define LEFT KEY_LEFT
#define RIGHT KEY_RIGHT
#define EXIT_GAME 'q'
typedef int graphics_input; //the type of the graphics input



void initializeGraphics(void);
void endGraphics(void);
void refreshScreen(void);
void printChar(int y, int x, graphics_input img);
void printMsg(int y, int x, char *str);
char readChar(int y, int x);
int readInpt();