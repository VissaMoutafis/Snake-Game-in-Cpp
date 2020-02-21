#pragma once

#include "Graphics.h"
#include "Snake.h"

class Controller{
private:
    Snake *snake; //the figure the controler controls
    graphics_input inpt;
public:
    Controller(Snake* _snake);
    Controller();
    ~Controller(); //default destructor

    graphics_input readInput(void);   //basic input methods: sets inpt to what it read if i tread something

    void act(void);                   //basic act method: acts like a joystick

    bool wantsToQuit(void);           //returns true of the user wants to quit
};