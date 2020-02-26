#include "Controller.h"
#include <assert.h>
#include <string>

using namespace std;

Controller::Controller()
: snack{SNACK} ,inpt{0}, currentScore{0}
{
    snake = new Snake();
    generateSnack(snack);
}

Controller::Controller(Snake *_snake)
: snake{_snake}, snack{SNACK}, inpt{0}, currentScore{0}
{

    assert(this->snake != NULL);
}

unsigned int Controller::getCurrScore(void){
    return this->currentScore;
}

void Controller::resetScore(void){
    this->currentScore = 0;
}

Controller::~Controller(){delete snake;}

static void printScore(unsigned int _score){
    string str = "Score: " + to_string(_score); 
    printMsg(-1, -1, (char*)str.c_str()); //-1, -1 because otherwise it'll be printed inside the game box
}

int Controller::act(void){

    if (snake->hasBitSnack(this->snack.getY(), this->snack.getX()) == true)
    {
        this->currentScore += 10;
        
        advanceDifficulty();
        generateSnack(this->snack);
        
        this->snake->incSize();

        printScore(currentScore);
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