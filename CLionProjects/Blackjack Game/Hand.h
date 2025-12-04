#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand {
private:
    vector<Card> cards;

public:
    void clear();
    void addCard(Card c);

    int getValue() const;
    bool isBlackjack() const;
    bool isBusted() const;

    void printHand(bool showAll = true) const;
};

#endif
