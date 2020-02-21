#include "Snack.h"
#include <cstdlib>

using namespace std;


const unsigned int snackScore = 10;

void generateSnack(Point &snack){

    int x, y;
    
    x = (rand() + 1) % GAME_RIGHT_WALL_X;
    y = (rand() + 1) % GAME_BOTTOM_WALL_Y;
    
    snack.setPoint(y, x);

    printChar(y, x, snack.getImg());
}
unsigned int getSnackScore(void){
    return snackScore;
}