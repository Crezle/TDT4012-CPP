#pragma once
#include "std_lib_facilities.h"

// 1a)

enum class Suit {
    clubs, 
    diamonds, 
    hearts, 
    spades
};

// 1b)

enum class Rank {
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};

#define SUIT_SIZE 4
#define RANK_SIZE 13

// 1c)

string suitToString(Suit s);

// 1d)

string rankToString(Rank r);

// 2a, b)

class Card {
private:
    Rank r;
    Suit s;

public:
    Card(Rank r, Suit s);
    Rank getRank()const;
    Suit getSuit()const;
    string getString();
    string toStringShort();
};