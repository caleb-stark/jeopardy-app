//
//  player.cpp
//  jeopardy-app
//

#include "player.hpp"

player(){
}
player(string name){
    setName(name);
    score=0;
}
void setName(string name){
    this->name=name;
}
void addScore(int points){
    score+=points;
}
string getName() const{
    return name;
}
int getScore() const{
    return score;
}