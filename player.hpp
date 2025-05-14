//
//  player.hpp
//  jeopardy-app
//

#pragma once
#include <string>
using namespace std;

class player{
private:
    string name;
    int score;
public:
    player();
    player(string name);
    void setName(string name);
    void setScore(int score);
    string getName() const;
    int getScore() const;
};
