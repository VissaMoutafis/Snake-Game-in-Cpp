
#include <ncurses.h>
#include <iostream>
#include "Controller.h"
using namespace std;

int main() {
    initializeGraphics();
    Controller c;
        /* CODE TO BE WRITTEN... */
    while(c.wantsToQuit() == false){
        c.readInput();
        if(c.act() == DEFEAT)
            break;
    }
    endGraphics();
    return 0;

}