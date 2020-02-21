#include "Controller.h"
#include <assert.h>

using namespace std;

Controller::Controller()
: snack{SNACK} ,inpt{0}
{
    snake = new Snake();
    generateSnack(snack);
}

Controller::Controller(Snake *_snake)
: snake{_snake}, snack{SNACK}, inpt{0}
{

    assert(this->snake != NULL);
}

Controller::~Controller(){}

int Controller::act(void){

    if (snake->hasBitSnack(this->snack.getY(), this->snack.getX()) == true)
    {
        generateSnack(this->snack);
        this->snake->incSize();
    }

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