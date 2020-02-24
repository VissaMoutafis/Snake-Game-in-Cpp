#include <iostream>
#include <string>
#include "Point.h"

/*snake will be an array of points*/

using namespace std;
Point::Point(int y, int x, graphics_input img)
: x {x}, y{y}, img{img}
{}
//delegating the previous constructor
Point::Point()
:Point(10, 10, '*')
{}

Point::~Point(){/*No need to do something */}

void Point::setPoint(int y, int x){
    this->x = x;
    this->y = y;
}

int Point::getX(void){
    return this->x;
}

int Point::getY(void){
    return this->y;
}

void Point::moveUp(void){
    y--;
}

void Point::moveDown(void){
    y++;
}

void Point::moveLeft(void){
    x--;
}

void Point::moveRight(void){
    x++;
}

graphics_input Point::getImg(){
    return this->img;
}
void Point::setImg(graphics_input image){
    this->img = image;
}
void Point::printImg(){
    printChar(this->y, this->x, this->img);
}
void Point::erase(void){
    this->img = ' ';
}