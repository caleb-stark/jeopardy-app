//
//  board.cpp
//  jeopardy-app
//
//  julian mendoza
//

#include "board.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

// Premade Questions
static const char *SAMPLE_QS[6][5]={
    {"2+2?", "3×3?", "√16?", "10−4?", "5+7?"},
    {"H₂O chemical name?", "Speed of light?", "Atomic number of C?", "Red Planet?", "pH of water?"},
    {"First US president?", "Year WW2 ended?", "Empire of Colosseum?", "Wall fell 1989?", "Magna Carta author?"},
    {"Author of '1984'?", "Play: star-crossed lovers?", "What is a haiku?", "Inventor of printing press?", "Iambic pentameter?"},
    {"Capital of France?", "Longest river?", "Highest mountain?", "Most timezones?", "Largest desert?"},
    {"Soccer team size?", "Sport with shuttlecock?", "Golf holes?", "Max bowling score?", "NBA court length?"}
};

// Premade answers
static const char *SAMPLE_AS[6][5]={
    {"4", "9", "4", "6", "12"},
    {"Water", "299792458", "6", "Mars", "7"},
    {"George Washington", "1945", "Roman", "Berlin Wall", "No single author"},
    {"George Orwell", "Romeo & Juliet", "A 3-line poem", "Johannes Gutenberg", "A 10-syllable line"},
    {"Paris", "Nile", "Everest", "France", "Antarctic"},
    {"11", "Badminton", "18", "300", "94"}
};

// Constructor
board::board(){
    const char *catNames[6]={"Math", "Science", "History", "Literature", "Geography", "Sports"};
    for (int i = 0; i < 6; ++i){
        categories[i] = catNames[i];
        for (int j = 0; j < 5; ++j){
            questions[i][j].category = categories[i];
            questions[i][j].text = SAMPLE_QS[i][j];
            questions[i][j].answer = SAMPLE_AS[i][j];
            questions[i][j].value = (j + 1) * 100;
            questions[i][j].used = false;
        }
    }
}

// Display the board
void board::display() const{
    for (int i = 0; i < 6; ++i)
        cout << setw(12) << categories[i];
    cout << '\n';
    for (int row = 0; row < 5; ++row){
        for (int col = 0; col < 6; ++col)
        {
            if (questions[col][row].used)
                cout << setw(12) << 'X';
            else
                cout << setw(12) << questions[col][row].value;
        }
        cout << '\n';
    }
}

// Get a question by category index and value
question board::getQuestion(const string &category, int value) const{
    for (int i = 0; i < 6; ++i){
        if (categories[i] == category){
            for (int j = 0; j < 5; ++j){
                if (!questions[i][j].used && questions[i][j].value == value)
                    return questions[i][j];
            }
        }
    }
    return {"", "", "", 0, true};
}

// Mark a question as used
void board::markUsed(const string &category, int value){
    for (int i = 0; i < 6; ++i){
        if (categories[i] == category){
            for (int j = 0; j < 5; ++j){
                if (questions[i][j].value == value){
                    questions[i][j].used = true;
                    return;
                }
            }
        }
    }
}