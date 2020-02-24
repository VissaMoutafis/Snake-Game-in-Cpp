#include "Snake.h"
#include <iostream>
using namespace std;

Snake::Snake(int headY, int headX)
:direction{LEFT}
{
    snake.push_back(Point{headY, headX, '>'}); //add the head of the snake
    for(int i=1; i<=3; i++)
        snake.push_back(Point{headY, headX+i, BODY});
}

Snake::~Snake(){}

bool Snake::isBitten(void){
    Point head = *snake.begin();

    list<Point>::iterator body_part = snake.begin();
    body_part++;
    while(body_part != snake.end()){
        if(body_part->getX() == head.getX() && body_part->getY() == head.getY())
            return true;
        body_part++;
    }

    return false;
}

bool Snake::hasBitSnack(int snackY, int snackX){
    return snake.begin()->getY() == snackY 
           && snake.begin()->getX() == snackX;
}

bool Snake::hasCrashedWall(void){
    Point &head = *snake.begin();

    return (head.getY() < GAME_TOP_WALL_Y)    ||
           (head.getY() > GAME_BOTTOM_WALL_Y) ||
           (head.getX() < GAME_LEFT_WALL_X)   ||
           (head.getX() > GAME_RIGHT_WALL_X);
}

int Snake::getSize(void){
    return snake.size();
}

void Snake::incSize(void){
    auto tail = snake.end();
    //since list::end() returns one element past the actual last one we will decrease by one the tail iterator
    tail--; //now we actually pointing to the tail
    int tailX = tail->getX();
    int tailY = tail->getY();

    //now we must determine the direction which is easy by just fiding the coordinates of the previous to tail element
    auto prev = --tail;
    int prevX = prev->getX();
    int prevY = prev->getY();

    if(prevY == tailY){ 
        //if the 2 part are on the same 'height'
        if (prevX < tailX)                                  //if the tail continues to the left:
            snake.push_back(Point{tailY, tailX + 1, BODY}); //  add one part to the right of the tail
        else if(prevX > tailX)                              //if the tail continues to the right:
            snake.push_back(Point{tailY, tailX - 1, BODY}); //  add one part to the left of the tail
    }else{
        if (prevY < tailY)                                  //if the tail continues to the upper side:
            snake.push_back(Point{tailY + 1, tailX, BODY}); //  add one part facing down
        else if (prevY > tailY)                             //if the tail continues to the lower side:
            snake.push_back(Point{tailY - 1, tailX, BODY}); //  add one part facing up
    }
}

void Snake::updateHead(void){
    auto head = snake.begin();
    switch (this->direction)
    {
    case UP:
        head->moveUp();
        break;

    case DOWN:
        head->moveDown();
        break;

    case LEFT:
        head->moveLeft();
        break;

    case RIGHT:
        head->moveRight();
        break;
    }
}

void Snake::printSnake(void){
    //We print each element of the snake-list
    for(auto bodyPart : snake){
        bodyPart.printImg();    
    }

    refreshScreen(); //finally call the previously implemented function at Graphics.cpp
                    //to update the screen so the changes become noticed
}

void Snake::move(void){
    //now delete the tail print since teh snake moves forward
    auto tail = snake.end();
    tail--;
    printChar(tail->getY(), tail->getX(), ' ');

    //and now we have to update all the other nodes of the body

    auto bodyP1 = tail;
    auto bodyP2 = --tail;

    while(bodyP2 != snake.begin()){
        *bodyP1 = *bodyP2;
        bodyP1--;
        bodyP2--;
    }

    //update the previous to head node
    auto headPrev = snake.begin();
    headPrev++;
    *headPrev = *snake.begin();
    headPrev->setImg(BODY);

    //based on direction, update the head
    this->updateHead();

    this->printSnake(); // print the snake and update the screen 
}

//Move Functions:
//For the move functions we must change 
void Snake::moveUp(void){
    snake.begin()->setImg('v');
    this->direction = UP;
    this->move();
}

void Snake::moveDown(void){
    snake.begin()->setImg('^');
    this->direction = DOWN;
    this->move();
}

void Snake::moveLeft(void){
    snake.begin()->setImg('>');
    this->direction = LEFT;
    this->move();
}

void Snake::moveRight(void){
    snake.begin()->setImg('<');
    this->direction = RIGHT;
    this->move();
}