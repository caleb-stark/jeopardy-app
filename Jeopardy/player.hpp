//
//  player.hpp
//  jeopardy-app
//

#pragma once

class player{
private:
    string name;
    int score;
public:
    player();
    player(string name, int score);
    void setName(string name);
    void setScore(int score);
    string getName() const;
    int getScore() const;
};
