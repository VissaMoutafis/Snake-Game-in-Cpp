#include "Graphics.h"
#include <chrono>
#include <thread>
#include <time.h>
#include <cstdlib>

///Utillities for the graphics
unsigned int sleepTime = 40000000;
static WINDOW *_box = NULL;

static void createBox(void){
    _box = newwin(LINES-2, COLS, 2, 0);
    box(_box, 0, 0);
    wrefresh(_box);
}
static void destroyBox(void){
    wborder(_box, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(_box);
    delwin(_box);
}
//Initialization function
void initializeGraphics(char* gameName){
    srand((unsigned int) time(NULL));

    initscr(); //initialize curses
    cbreak(); //set line buffering to false
    noecho(); //set input echo to false
    keypad(stdscr, TRUE); //this step enables the use of arrow keys and other function keys
    nodelay(stdscr, true);
    curs_set(0); //to hide the cursor
    //We must clear the screen from unecessary garbage
    clear();
    //Print the title
    mvprintw(0, (COLS/2) - 12, gameName);
    refresh();
    
    //create the game box
    createBox();
}

//Exit function
void endGraphics(void){
    curs_set(1);
    destroyBox();
    endwin();
}

//Typical refresh function (ease the eye with a custom function instead of the actual one)
void refreshScreen(void){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;      // nanoseconds, system_clock, seconds
    sleep_for(nanoseconds(sleepTime));
    
    refresh(); // just use the curses version ;p
    wrefresh(_box);
}

void printChar(int y, int x, graphics_input img){
    mvwaddch(_box, y, x, img);
    refresh();
    wrefresh(_box);
}

void printMsg(int y, int x, char* str){
    if(y>0 && x>0)
        mvwaddstr(_box, y, x, str);
    else{
        if(y < 0) y = 2 + y;
        if(x < 0) x = 0;
        mvaddstr(y, x, str);
    }
    refresh();
    wrefresh(_box);
}

char readChar(int y, int x){
    refresh();
    wrefresh(_box);
    return mvwgetch(_box, y, x);
}

int readInpt(){
    return getch();
}

void advanceDifficulty(void){
    if(sleepTime > 28000000) // we set 28000000 as teh min sleep time
        sleepTime -= 1000000;
}