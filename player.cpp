//
//  player.cpp
//  jeopardy-app
//

#include "player.hpp"

// Constructor
player::player(string name){
    setName(name);
    score = 0;
}

// Set the player name
void player::setName(string name){
    this->name = name;
}

// Adds to the player score
void player::addScore(int points){
    score += points;
}

// Gets player name
string player::getName() const{
    return name;
}

// Gets player score
int player::getScore() const{
    return score;
}