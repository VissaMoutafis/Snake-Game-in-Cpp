#pragma once

#include <list>

#include "Point.h" //the library we need to implement the snake
#define SNACK '*'
#define BODY 'o'
class Snake{
private:
    std::list<Point> snake; //the snake will be implemented as a list of points where the first element is the head
    graphics_input direction;
    void updateHead(void);
    void printSnake(void);
public:
    Snake(int headY = LINES/2, int headX = COLS/2); //default constructor
    ~Snake(); //destructor

    //basic move functions
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);

    bool isBitten(void);                     //function to check if the snake bit its self
    bool hasBitSnack(int snackY, int snackX);//checks if the snake has bitten a snack

    int getSize(void);                       //get the current length
    void incSize(void);                      //function to increase the length

    void move(void);                         //function to refresh the image of the snake
};
