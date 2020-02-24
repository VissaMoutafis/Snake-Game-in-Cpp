#include "Player.h"

using namespace std;

Player::Player()
: name{"Unknown"}, points{0}, timesPlayed{0}
{}

Player::Player(string _name)
: name{_name}, points{0}, timesPlayed{0}
{}

Player::~Player()
{/* No need to do something */}

string Player::getName(void){
    return this->name;
}

void Player::addPoints(unsigned int _points){
    points += _points;
}

unsigned int Player::getPoints(void){
    return this->points;
}

std::pair<std::string, unsigned int>  Player::play(void){
    //here we will implement the basic loop of the game since each player has its remote controller
    //and can play the game
    Controller controller;
    while (controller.wantsToQuit() == false)
    {
        controller.readInput();
        if (controller.act() == DEFEAT)
            break;
    }

    points = controller.getCurrScore();
    controller.resetScore();

    return {this->name, points};
}