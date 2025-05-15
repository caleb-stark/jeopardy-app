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
public:
    game(string p1, string p2);
    void start(int numQuestions);
private:
    board board;
    player players[2];
    int currentTurn;
};
