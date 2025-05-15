//
//  game.cpp
//  jeopardy-app
//

#include "game.hpp"

#include <iostream>
// Constructor
game::game(string p1, string p2) : players{player(p1), player(p2)}{
  currentTurn = 0;
}

// Start the game
void game::start(int numQuestions){
  for (int i = 0; i < numQuestions; i++){
    board.display();
    cout << players[i % 2].getName() << "'s turn" << endl;
    string category;
    int value;
    cout << "Choose a category (0-5)" << endl;
    getline(cin, category);
    cout << "Pick a dollar value (100, 200, ..., 500)" << endl;
    cin >> value;
    cin.ignore();
    question q = board.getQuestion(category, value);
    while (q.used){
      cout << "Invalid input, please try again" << endl;
      cout << "Choose a category (0-5)" << endl;
      getline(cin, category);
      cout << "Pick a dollar value (100, 200, ..., 500)" << endl;
      cin >> value;
      cin.ignore();
      q = board.getQuestion(category, value);
    }
    cout << "Category: " << q.category << endl;
    cout << "question: " << q.text << endl;
    cout << "value: " << q.value << endl;
    string answer;
    cout << players[i % 2].getName() << "'s guess: " << endl;
    getline(cin, answer);
    if (q.answer == answer){
      cout << "Correct!" << endl;
      players[i % 2].addScore(q.value);
      board.markUsed(q.category, q.value);
    }else{
      cout << "Wrong!" << endl;
      cout << q.answer << endl;
      board.markUsed(q.category, q.value);
    }
  }

  cout << players[0].getName() << "'s points: " << players[0].getScore() << endl;
  cout << players[1].getName() << "'s points: " << players[1].getScore() << endl;
  if (players[0].getScore() > players[1].getScore()){
    cout << "winner is " << players[0].getName() << endl;
  }else if (players[1].getScore() > players[0].getScore()){
    cout << "winner is " << players[1].getName() << endl;
  }else{
    cout << "TIE!" << endl;
  }
}