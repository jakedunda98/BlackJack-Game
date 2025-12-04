#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() : index(0) {
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> ranks = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

    for (auto &s : suits) {
        for (auto &r : ranks) {
            int v;
            if (r == "A") v = 11;
            else if (r == "J" || r == "Q" || r == "K") v = 10;
            else v = stoi(r);

            cards.emplace_back(r, s, v);
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
    index = 0;
}

Card Deck::dealCard() {
    if (index >= cards.size())
        shuffleDeck();
    return cards[index++];
}
