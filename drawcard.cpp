// Function that will choose a random card out of the deck and replace the card drawn within
// the deck with "0", and then return the card that was drawn

#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
string drawCard(string deck[4][13]) {
    int i=0, j=0;
    string drawnCard = "0";
    srand(time(0));
    while (drawnCard == "0") {
        i = rand() % 4;
        j = rand() % 13;
        drawnCard = deck[i][j];
    }
    deck[i][j] = "0";
    return drawnCard;
}

