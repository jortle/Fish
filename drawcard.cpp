#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function that will choose a random card out of the deck and replace the card drawn within
// the deck with "0", and then return the card that was drawn
string drawCard(string deck[4][13]) {
  int i = 0, j = 0;
  string drawnCard = "  ";
  srand(time(0));
  while (drawnCard == "  ") {
    i = rand() % 4;
    j = rand() % 13;
    drawnCard = deck[i][j];
  }
  deck[i][j] = "  ";
  return drawnCard;
}
