#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

// 3)

class CardDeck {
private:
    vector<Card> Cards;

public:
    CardDeck();
    void swap(int a, int b);
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
};