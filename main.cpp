#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Random number generator

    // Deck of cards
    string deck[52] = {
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS",
        "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD",
        "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC",
        "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH"
    };

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
        int index;

        // Dealing to player
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

    // Print player's hand
    cout << "Player's Hand:    ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << "[" << playerHand[i] << "] ";
    }
    cout << endl;

    // Print computer's hand
    cout << "Computer's Hand:  ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << "[" << computerHand[i] << "] ";
    }
    cout << endl;

    return 0;
}



