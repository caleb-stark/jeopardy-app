//
//  game.cpp
//  jeopardy-app
//

#include "game.hpp"

#include <iostream>
// Constructor
// - Ask for names of 2 players
// - Create Player objects and store them in the players array
// - Set turn counter to 0 (Player 1 starts)
game::game(string p1, string p2) : players{player(p1), player(p2)} {
  currentTurn = 0;
}

// Start the game
// - Loop for a fixed number of turns (e.g. 15 questions total)
//     1. Show the current state of the board
//     2. Tell the current player it's their turn
//     3. Ask the player to choose a category (index 0–5)
//     4. Ask for a dollar value (100, 200, ..., 500)
//     5. Get the question from the board
//         - If invalid or already used, show a message and skip turn
//     6. If valid, show the question text
//     7. Ask the player for their answer
//     8. Compare their answer to the correct answer
//         - If correct, add points to their score
//         - If wrong, show the correct answer
//     9. Mark the question as used
//    10. Switch to the other player's turn

// After all turns
// - Show both players' scores
// - Declare the winner (or a tie)
void game::start(int numQuestions){
  board board();

  for (int i = 0; i < numQuestions; i++) {
    board.display();
    cout << players[i%2].getName() << "'s turn" << endl;
    string category;
    string value;
    cout << "Choose a category (0-5)" << endl;
    getline(cin, category);
    cout << "Pick a dollar value (100, 200, ..., 500)" << endl;
    getline(cin, value);
    while (board.getQuestion(category, value) == nullptr) {
      cout << "Invalid input, please try again" << endl;
      cout << "Choose a category (0-5)" << endl;
      getline(cin, category);
      cout << "Pick a dollar value (100, 200, ..., 500)" << endl;
      getline(cin, value);
    }
    question q = board.getQuestion(category, value);
    cout << "Category: "<< q.category << endl;
    cout << "question: "<< q.text << endl;
    cout << "value: "<< q.value << endl;
    string answer;
    cout << players[i%2].getName() << "'s guess: " << endl;
    getline(cin, answer);
    if (q.answer == answer) {
      cout << "Correct!" << endl;
      players[i%2].setScore(q.value);
      board.markUsed(q.category, q.value);
    } else {
      cout << "Wrong!" << endl;
      cout << q.answer << endl;
      board.markUsed(q.category, q.value);
    }
  }

  cout << players[0].getName() << "'s points: " << players[0].getScore() << endl;
  cout << players[1].getName() << "'s points: " << players[1].getScore() << endl;
  if (players[0].getScore() > players[1].getScore()) {
    cout << "winner is " << players[0].getName() << endl;
  } else if (players[1].getScore() > players[0].getScore()) {
    cout << "winner is " << players[1].getName() << endl;
  } else {
    cout << "TIE!" << endl;
  }
}