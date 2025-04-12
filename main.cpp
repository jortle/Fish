#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {

   // array for deck of cards - Done
   // function for drawing cards out of the deck - make 0 in the deck, while loop to not draw a 0 card - Kace 
   // Another array for both computer's hand and player's hand - Spaces as filler strings if hand not full - Makenzie
   // Function for computer asking if player has any of the cards in the computer's array (Yes/no option maybe?) - John
   // Function for player asking if computer has any of the cards in their array - John
   // Keep track of the pairs that are made (somehow? Point system?)

   //The deck
string deck[4][13] =   {"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS",
                       "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD",
                       "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC",
                       "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH"};

    // Hands for player and computer
    //Player and computer hand size is 7
    const int handSize = 7;
    const int maxHandSize = 13;
    string playerHand[maxHandSize];
    string computerHand[maxHandSize];

    // Fill hands with "spaces" to represent no cards in that place
    for (int i = 0; i < maxHandSize; i++) {
        playerHand[i] = "  ";
        computerHand[i] = "  ";
    }

    // Deal 7 cards to player and computer
    for (int i = 0; i < initialHandSize; i++) {
        int index;

        // Dealing to player
        //XX is a card that has already been taking
        do {
            index = rand() % 52;
        } while (deck[index] == "XX");
        playerHand[i] = deck[index];
        deck[index] = "XX";

        // Dealing to computer
        do {
            index = rand() % 52;
        } while (deck[index] == "XX");
        computerHand[i] = deck[index];
        deck[index] = "XX";
    }

    // Printing the player's hand
    cout << "Player's Hand:    ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << "[" << playerHand[i] << "] ";
    }
    cout << endl;

    // Printing the computer's hand
    cout << "Computer's Hand:  ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << "[" << computerHand[i] << "] ";
    }
    cout << endl;


srand(time(0));
       cout << deck[rand() % 4][rand() % 13] << endl;
   return 0;
}



