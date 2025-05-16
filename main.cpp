//
//  main.cpp
//  jeopardy-app
//
//  caleb stark
//

#include <iostream>
#include "game.hpp"

int main(){
    game g = game("p1", "p2");
    g.start(30);
    return 0;
}
