

#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function that will choose a random card out of the deck and replace the card drawn within
// the deck with "0", and then return the card that was drawn
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

template <typename T>
// sorts the hands so highest is at the top
void sort(T arr[]) {
    for (int i = 0; i < 13 - 1; i++) {
        for (int j = i + 1; j < 13; j++) {
            if (arr[i] < arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//function to print the whole hand
void print(string arr[]) {
    for (int i = 0; i < 13; i++) {
        cout << arr[i] << " ";
    }
}