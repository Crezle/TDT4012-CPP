#pragma once
#include "std_lib_facilities.h"
#include "Card.h"


class Blackjack {
private:
    vector<Card> deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;

public:
    Blackjack();
    void drawCard();
    void handPrint();
    void dealerPrint();
    int handValue();
    int dealerValue();
    void printStatus();
    char prompt();
    void endGame();
    /* void printShort(); */
    /* void shuffle(); */
    /* void swap(int a, int b); */
};

void playBlackjack();