#include "./asks.cpp"
#include "./drawcard.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void removeCard(string hand[], int &handSize, string cardToRemove) {
  // Find the card position
  char valueToRemove = cardToRemove[0];


  for (int i = 0; i < handSize; i++) {
    if (hand[i][0] == valueToRemove) {
      // Shift all cards after this position left by one
      for (int j = i; j < handSize - 1; j++) {
        hand[j] = hand[j + 1];
      }
      handSize--; // Decrease the hand size

      return; // Exit after removing first occurrence

    }
  }
}

void gameLoop(string playerHand[7], string computerHand[7],
              string Deck[4][13]) {
  srand(time(0));
  int playerScore = 0;
  int computerScore = 0;
  int firstToGo = rand() % 2;
  int playerHandSize = 7;
  int computerHandSize = 7;
  int computerMaxHand = 13;
  int playerMaxHand = 13;
  string card;
  bool playerTurn;

  // Determine who goes first
  playerTurn = (firstToGo == 0);


  // Main game loop
  while (playerScore < 3 && computerScore < 3) {

    if (playerTurn) {
      // Player's turn
      do {
        card = playerAsks(playerHand, playerHandSize);
        bool hasCard = computerHasCard(computerHand, computerHandSize, card);

        if (hasCard) {
          cout << "The computer has the card " << card << endl;
          // Remove card from both hands and update sizes
          removeCard(playerHand, playerHandSize, card);
          removeCard(computerHand, computerHandSize, card);
          playerScore++;
          cout << "Your score is now: " << playerScore << endl;
        } else {
          cout << "Go Fish!" << endl;
          // Draw card logic here
          if (playerHandSize < playerMaxHand) {
            playerHand[playerHandSize] = drawCard(Deck);
            playerHandSize++;
          }
          playerTurn = false; // End player's turn
          break;
        }
      } while (computerHasCard(computerHand, computerHandSize, card) &&
               playerHandSize > 0 && computerHandSize > 0);
    } else {
      // Computer's turn
      do {
        card = computerAsks(computerHand, computerHandSize);
        cout << "Computer asks for: " << card << endl;
        bool hasCard = playerHasCard(playerHand, playerHandSize, card);

        if (hasCard) {
          cout << "You have the card " << card << endl;
          // Remove card from both hands and update sizes
          removeCard(playerHand, playerHandSize, card);
          removeCard(computerHand, computerHandSize, card);
          computerScore++;
          cout << "Computer score is now: " << computerScore << endl;
          continue;
        } else {
          cout << "Computer goes fishing!" << endl;
          // Draw card logic here
          if (computerHandSize < computerMaxHand) {
            computerHand[computerHandSize] = drawCard(Deck);
            computerHandSize++;
          }
          playerTurn = true; // End computer's turn
          break;
        }
      } while (playerHasCard(playerHand, playerHandSize, card) &&
               playerHandSize > 0 && computerHandSize > 0);
    }
  }


  // Announce winner
  cout << "\nGame Over!\n";
  cout << "Final Scores:\n";
  cout << "Player: " << playerScore << endl;
  cout << "Computer: " << computerScore << endl;

  if (playerScore > computerScore) {
    cout << "You win!" << endl;
  } else if (computerScore > playerScore) {
    cout << "Computer wins!" << endl;
  } else {
    cout << "It's a tie!" << endl;
  }
}

int main() {

  // Deck of cards
  string Deck[4][13] = {
      "AS",  "2S", "3S",  "4S", "5S",  "6S", "7S", "8S", "9S", "10S", "JS",
      "QS",  "KS", "AD",  "2D", "3D",  "4D", "5D", "6D", "7D", "8D",  "9D",
      "10D", "JD", "QD",  "KD", "AC",  "2C", "3C", "4C", "5C", "6C",  "7C",
      "8C",  "9C", "10C", "JC", "QC",  "KC", "AH", "2H", "3H", "4H",  "5H",
      "6H",  "7H", "8H",  "9H", "10H", "JH", "QH", "KH"};

  // Player and computer hands
  const int handSize = 7;
  const int maxHandSize = 13;
  string playerHand[maxHandSize];
  string computerHand[maxHandSize];

  // Fill hands with spaces as blank spots
  for (int i = 0; i < maxHandSize; i++) {
    playerHand[i] = "  ";
    computerHand[i] = "  ";
  }

  // Deal 7 cards to player and computer
  for (int i = 0; i < handSize; i++) {
    // Dealing to player
    playerHand[i] = drawCard(Deck);

    // Dealing to computer
    computerHand[i] = drawCard(Deck);
  }

  gameLoop(playerHand, computerHand, Deck);

  return 0;
}
