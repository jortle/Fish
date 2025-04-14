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
