//
//  board.hpp
//  jeopardy-app
//

#pragma once
#include <string>
using namespace std;

struct Question{
    string category;
    string text;
    string answer;
    int value;
    bool used;

}
class board{
private:
    Question questions[6][5];
    string categories[6]
public:
    board();
    void display();
    Question getQuestion(string category, int value);
    void markUsed(string category, int value);
};
