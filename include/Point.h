#pragma once

#include "Graphics.h"

class Point{
private:
    int x;
    int y;
    graphics_input img;
public:
    Point();
    Point(int y = 10, int x = 10, graphics_input img = '*');
    ~Point();
    void setPoint(int y, int x);
    int getX();
    int getY();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    graphics_input getImg();
    void setImg(graphics_input image);
    void printImg();
    void erase();
    void randomize();
};