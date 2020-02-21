#include "Controller.h"
#include <assert.h>
#include <iostream>
using namespace std;

Controller::Controller()
:inpt{0}
{
    snake = new Snake();
}

Controller::Controller(Snake *_snake)
: snake{_snake}, inpt{0} {

    assert(this->snake != NULL);
}

Controller::~Controller(){}

void Controller::act(void){
    switch (this->inpt)
    {
    case UP:
            snake->moveUp();
        break;
    case DOWN:
            snake->moveDown();
        break;
    case LEFT:
            snake->moveLeft();
        break;
    case RIGHT:
            snake->moveRight();
        break;
    default:
        snake->move();
    break;
    }
    refreshScreen();
}

graphics_input Controller::readInput(void){
    this->inpt = readInpt();
    refreshScreen();
    return inpt;
}

bool Controller::wantsToQuit(void){
    return this->inpt == EXIT_GAME;
}