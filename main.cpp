//
//  main.cpp
//  jeopardy-app
//

#include <iostream>
#include "game.hpp"

int main(){
    game g = game("p1", "p2");
    g.start(30);
    return 0;
}
