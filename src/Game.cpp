#include "Game.h"
#include <algorithm>
#include <limits.h>
using namespace std;

SnakeGame::SnakeGame()
:gameName{"~Snake Game by VissaM~"},highScore{0}, bestPlayer{"None"}
{}

SnakeGame::~SnakeGame(){}

void SnakeGame::addPlayer(string playerName){
    players.emplace_back( Player{playerName} );
}

unsigned int SnakeGame::getHighScore(void){
    return highScore;
}

string SnakeGame::getBestPlayer(void){
    return bestPlayer;
}

void SnakeGame::play(string playerName){
    pair<string, unsigned int> curBest{playerName, 0};
    for(auto player : players){
        if(player.getName() == playerName){
            initializeGraphics((char *)gameName.c_str());
            curBest = player.play();
            endGraphics();
            break;
        }
    }

    if(curBest.second > highScore){
        highScore = curBest.second;
        bestPlayer = curBest.first;
    }

    cout << "Highscore: " << highScore << " by " << bestPlayer << "\n" <<endl;
}

void SnakeGame::play(void){
    while(1){
        string playerName;
        cout << "Who's playing: ";
        cin >> playerName;
        cout << endl;

        list<Player>::iterator p;
        for(p=players.begin(); p!=players.end(); p++){
            if(p->getName() == playerName)
                break;  
        }

        if(p == players.end()){
            //if the player isn't in the list, add him/her
            addPlayer(playerName);
        }

        
        play(playerName); //get the player to play the game

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Do you want to play again? (yes or no): ";
        string ans;
        
        cin >> ans;
        
        if(ans != "yes"){
            cout << "Exiting ..." << endl;
            break;
        }
        cout << "Perfect...\n" << endl;
    }
}