
#include <ncurses.h>
#include <iostream>
#include "Controller.h"
using namespace std;

int main() {
    initializeGraphics();
    Controller c;
        /* CODE TO BE WRITTEN... */
        graphics_input in;
    while(c.wantsToQuit() == false){
        c.readInput();
        c.act();
        
    }
    endGraphics();
    return 0;

}