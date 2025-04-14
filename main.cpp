#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "./drawcard.cpp"
#include "./asks.cpp"
using namespace std;

int main() {

    // Deck of cards
    string Deck[4][13] =   {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King",
                           "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King",
                           "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King",
                           "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // Player and computer hands
    const int handSize = 7;
    const int maxHandSize = 13;
    string playerHand[maxHandSize];
    string computerHand[maxHandSize];

    //set point system up
    int playerPairs = 0, computerPairs = 0;

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

    // Print player's hand
    cout << "Player's Hand:    ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << playerHand[i] << " ";
    }
    cout << endl;

    // Print computer's hand
    cout << "Computer's Hand:  ";
    for (int i = 0; i < maxHandSize; i++) {
        cout << computerHand[i] << " ";
    }
    cout << endl;

    //trying to make a loop for actual gameplay
    string newCard;
    cout << "Player's hand: " ; print(playerHand);
    cout << endl;
    sort(playerHand);
    cout << endl;
    cout << "Player's sorted hand: "; print(playerHand);
    /*while (playerPairs < 3 or computerPairs < 3) {
        cout << Player1(playerHand);
        if computer has card{
        playerPairs++;
            card in hand = " ";
            card in computers hand = " ";
            cout << Player1(playerHand);
        }
        else if computer !have card{
        cout << "Go fish!"
            newCard = drawCard(Deck)

        }
    }*/
    return 0;

}



