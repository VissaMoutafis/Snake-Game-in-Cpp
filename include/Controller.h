#pragma once

#include "Graphics.h"
#include "Snake.h"

#define DEFEAT -1

class Controller{
private:
    Snake *snake; //the figure the controler controls
    Point snack;
    graphics_input inpt;
    unsigned int currentScore;
public:
    Controller(Snake* _snake);
    Controller();
    ~Controller(); //default destructor

    unsigned int getCurrScore(void);
    void resetScore(void);
    graphics_input readInput(void);   //basic input methods: sets inpt to what it read if i tread something

    int act(void);                   //basic act method: acts like a joystick

    bool wantsToQuit(void);           //returns true of the user wants to quit
};