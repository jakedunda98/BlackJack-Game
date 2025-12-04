#include "Game.h"
#include <iostream>
using namespace std;

void Game::play() {
    cout << "###########################\n";
    cout << "#  The Game of Blackjack  #\n";
    cout << "###########################\n\n";

    char choice = 'y';

    while (choice == 'y') {
        startRound();
        cout << "\nplay another round? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Thanks for playing!" << endl;
}

void Game::startRound() {
    player.clear();
    dealer.clear();

    // Initial deal
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    // Immediate blackjack checks
    if (player.isBlackjack() && dealer.isBlackjack()) {
        showHands(true);
        cout << "Dang, dealer has blackjack too. You push.\n";
        return;
    }
    if (player.isBlackjack()) {
        showHands(true);
        cout << "Blackjack! You win!\n";
        return;
    }
    if (dealer.isBlackjack()) {
        showHands(true);
        cout << "Dealer has Blackjack. You lose.\n";
        return;
    }

    // PLAYER TURN
    char action = 'h';
    while (action == 'h') {
        cout << "Dealer's Show Card:\n";
        dealer.printHand(false);

        cout << "\nYour Cards:\n";
        player.printHand(true);

        cout << "\nhit or stand? (h/s): ";
        cin >> action;

        if (action == 'h') {
            player.addCard(deck.dealCard());
            if (player.isBusted()) {
                showHands(true);
                cout << "Sorry. You busted. You lose.\n";
                return;
            }
        }
    }

    // DEALER TURN (soft 17 rule)
    while (dealer.getValue() < 17) {
        dealer.addCard(deck.dealCard());
    }

    showHands(true);

    int p = player.getValue();
    int d = dealer.getValue();

    if (dealer.isBusted())
        cout << "Yay! The dealer busted. You win!\n";
    else if (p > d)
        cout << "Hooray! You win!\n";
    else if (p < d)
        cout << "Sorry. You lose.\n";
    else
        cout << "It's a tie! You push.\n";
}

void Game::showHands(bool showAll) {
    cout << "\nDealer's Cards:\n";
    dealer.printHand(showAll);

    cout << "\nYour Cards:\n";
    player.printHand(true);

    cout << "\nYour Points:     " << player.getValue() << endl;
    cout << "Dealer's Points: " << dealer.getValue() << endl;
}
