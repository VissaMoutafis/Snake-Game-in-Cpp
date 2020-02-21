#include "Controller.h"
#include <assert.h>

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

int Controller::act(void){
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
    
    if(snake->isBitten()) 
        return DEFEAT;
    if (snake->hasCrashedWall())
        return DEFEAT;
    return 0;
}

graphics_input Controller::readInput(void){
    this->inpt = readInpt();
    refreshScreen();
    return inpt;
}

bool Controller::wantsToQuit(void){
    return this->inpt == EXIT_GAME;
}