#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    vector<Card> cards;
    int index;

public:
    Deck();
    void shuffleDeck();
    Card dealCard();
};

#endif