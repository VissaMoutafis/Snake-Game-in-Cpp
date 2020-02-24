#pragma once

//This class will be the abstract Game Interface
#include <string>
#include "Controller.h"
#include "Snake.h"
#include "Player.h"
class SnakeGame{
private:
    std::string gameName;
    std::list<Player> players;
    unsigned int highScore;
    std::string bestPlayer;
    
    void play(std::string playerName);
    void addPlayer(std::string playerName);

public:
    SnakeGame(); //intialize graphics and set the game screen
    ~SnakeGame();

    
    unsigned int getHighScore(void);
    std::string getBestPlayer(void);

    //print the statistics (highest score & games played) of each player
    //void printGameStatistics(void);

    void play(void);
};