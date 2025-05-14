//
//  player.cpp
//  jeopardy-app
//

#include "player.hpp"

player::player(){
}
player::player(string name){
    setName(name);
    score=0;
}
void player::setName(string name){
    this->name=name;
}
void player::addScore(int points){
    score+=points;
}
string player::getName() const{
    return name;
}
int player::getScore() const{
    return score;
}