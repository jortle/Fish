// Function for computer asking if player has any of the cards in the computer's
// array (Yes/no option maybe?) - John Function for player asking if computer
// has any of the cards in their array - John

// function takes in an array of cards and returns a boolean value of whether
// the pair exists game loop - player then computer take turns asking if the
// other has a card in their hand. when computer ask if a player has a card, we
// have the option of checking our hand or just answering the question checking
// hand prints out the hand to the terminal then asks us again when player asks
// if computer has a card we use a function to loop through the computer's hand
// and check if it exists the computer then prints out the bool to the terminal

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

string playerAsks(string hand[], int size) {
  string card = "  ";
  while (card == "  ") {
    cout << "What card would you like to check for" << endl;
    for (int i = 0; i < size; i++) {
      cout << hand[i] << " ";
    }
    cout << endl;
    cin >> card;
  }
  return card;
}

string computerAsks(string hand[], int size) {
  srand(time(0));
  int cardNum = rand() % size;
  string card = hand[cardNum];

  return card;
}

bool playerHasCard(string hand[], int size, string card) {
  char targetValue = card[0];
  bool hasCard = false;
  string MyAnswer = "no";
  for (int i = 0; i < size; i++) {
    cout << hand[i] << " ";
  }
  cout << endl;
  cout << "Do you have a " << targetValue << "?" << endl;
  cin >> MyAnswer;
  if (MyAnswer == "yes") {
    hasCard = true;
  }
  return hasCard;
}

bool computerHasCard(string hand[], int size, string card) {
  char targetValue = card[0];
  for (int i = 0; i < size; i++) {
    if (hand[i][0] == targetValue) {
      return true;
    }
  }
  return false;
}
string Player1(string playerhand[]) {
  string query;
  cout << "Your hand is: ";
  for (int i = 0; i < 13; i++) {
    cout << playerhand[i] << " ";
  }
  cout << endl;
  cout << "Which card do you want to ask for?";
  cin >> query;
  return query;


}