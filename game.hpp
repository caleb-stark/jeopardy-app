//
//  game.hpp
//  jeopardy-app
//

#pragma once
#include <string>
#include "player.hpp"
#include "board.hpp"
using namespace std;

class game{
private:
    Board board;
    Player players[2];
    int currentTurn;
public:
    game();
    void start();
};
