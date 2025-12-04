#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
private:
    string suit;
    string rank;
    int value;

public:
    Card(string r, string s, int v);

    string getSuit() const;
    string getRank() const;
    int getValue() const;

    string toString() const;
};

#endif