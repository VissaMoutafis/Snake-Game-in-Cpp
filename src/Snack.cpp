#include "Snack.h"
#include <cstdlib>

using namespace std;


const unsigned int snackScore = 10;

void generateSnack(Point &snack){

    int x, y;
    
    x = rand() % GAME_RIGHT_WALL_X + 1;
    y = rand() % GAME_BOTTOM_WALL_Y + 1;
    
    snack.setPoint(y, x);

    printChar(y, x, snack.getImg());
}
unsigned int getSnackScore(void){
    return snackScore;
}