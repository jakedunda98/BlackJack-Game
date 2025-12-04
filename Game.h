#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Hand.h"

class Game {
private:
    Deck deck;
    Hand player;
    Hand dealer;

public:
    void play();

private:
    void startRound();
    void showHands(bool showAll);
};

#endif
