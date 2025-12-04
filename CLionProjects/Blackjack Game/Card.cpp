#include "Card.h"

Card::Card(string r, string s, int v) : rank(r), suit(s), value(v) {}

string Card::getSuit() const { return suit; }
string Card::getRank() const { return rank; }
int Card::getValue() const { return value; }

string Card::toString() const {
    return rank + " of " + suit;
}
