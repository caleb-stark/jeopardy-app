//
//  board.hpp
//  jeopardy-app
//

#pragma once
#include <string>
using namespace std;

struct question{
    string category;
    string text;
    string answer;
    int value;
    bool used;
};

class board{
private:
    question questions[6][5];
    string categories[6];

public:
    board();
    void display() const;
    question getQuestion(const string &category, int value) const;
    void markUsed(const string &category, int value);
};
