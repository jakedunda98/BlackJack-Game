#include "Hand.h"
#include <iostream>

void Hand::clear() {
    cards.clear();
}

void Hand::addCard(Card c) {
    cards.push_back(c);
}

int Hand::getValue() const {
    int sum = 0;
    int aces = 0;

    for (auto &c : cards) {
        sum += c.getValue();
        if (c.getRank() == "A") aces++;
    }

    // adjust Aces
    while (sum > 21 && aces > 0) {
        sum -= 10;
        aces--;
    }

    return sum;
}

bool Hand::isBlackjack() const {
    return cards.size() == 2 && getValue() == 21;
}

bool Hand::isBusted() const {
    return getValue() > 21;
}

void Hand::printHand(bool showAll) const {
    if (!showAll) {
        cout << cards[0].toString() << endl;
        return;
    }

    for (auto &c : cards)
        cout << c.toString() << endl;
}
