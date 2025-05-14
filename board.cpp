//
//  board.cpp
//  jeopardy-app
//

#include "board.hpp"

// Constructor
// - Initialize the 6 category names (e.g., Math, Science, etc.)
// - Set question values (100–500)
// - Fill the 6x5 questions array with hardcoded questions and answers
// - Mark all questions as not used
board::board(){

}

// Display the board
// - Print category names at the top
// - For each row (100, 200, ..., 500):
// - Print the value or "X" if the question has been used
void board::display{

}

// Get a question by category index and value
// - Search the questions in the specified category
// - Return a pointer to the matching question if it’s not used
// - Return nullptr if it’s already used or not found
question getQuestion(string category, int value){

}

// Mark a question as used
// - Find the question matching the given category index and value
// - Set its used flag to true
void markUsed(string category, int value){
    
}