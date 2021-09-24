#include "Card.h"

// 1c)

string suitToString(Suit s) {
    map<Suit, string> stringConvert{
        {Suit::clubs,"Clubs"},
        {Suit::diamonds,"Diamonds"},
        {Suit::hearts,"Hearts"},
        {Suit::spades,"Spades"}};

    string rString = stringConvert[s];
    return rString; 
}

// 1d)

string rankToString(Rank r) {
    map<Rank, string> stringConvert{
        {Rank::two,"Two"},
        {Rank::three,"Three"},
        {Rank::four,"Four"},
        {Rank::five,"Five"},
        {Rank::six,"Six"},
        {Rank::seven,"Seven"},
        {Rank::eight,"Eight"},
        {Rank::nine,"Nine"},
        {Rank::ten,"Ten"},
        {Rank::jack,"Jack"},
        {Rank::queen,"Queen"},
        {Rank::king,"King"},
        {Rank::ace,"Ace"}};

    string rString = stringConvert[r];
    return rString;
}

// 1e)
// Klassens verdier er lettere å tolke og er lettere å referere til.

// 2)

Card::Card(Rank r, Suit s): r{r}, s{s} { // Gir r og s direkte til objektet
}

Rank Card::getRank()const{
    return r;
}

Suit Card::getSuit()const{
    return s;
}

string Card::getString() {
    string rank = rankToString(r);
    string suit = suitToString(s);
    string title = rank + " of " + suit;

    return title;
}

string Card::toStringShort() {
    int rankNum = static_cast<int>(r);
    string rank = to_string(rankNum);

    string suit = suitToString(s);
    string shortTitle = suit[0] + rank;

    return shortTitle;
}