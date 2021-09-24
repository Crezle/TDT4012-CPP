#include "CardDeck.h"

// 3b)

CardDeck::CardDeck() {
    Cards.clear();
    for (int suit = 0; suit < SUIT_SIZE; suit++) {
        for (int rank = 0; rank < RANK_SIZE; rank++) {
            Cards.push_back(Card{Rank{rank+2},Suit{suit}});
        }
    }
}

// 3c)

void CardDeck::swap(int a, int b) {
    Card temp = Cards[a];
    Cards[a] = Cards[b];
    Cards[b] = temp;
}

// Denne funksjonen har vi satt som public, ettersom vi vil at brukere
// skal kunne bytte kort. (Altså ikke noe å holde privat)

// 3d)

void CardDeck::print() {
    for (int card = 0; card < static_cast<int>(Cards.size()); card++) {
        cout << Cards[card].getString() << endl;
    }
}

// 3e)

void CardDeck::printShort() {
    for (int card = 0; card < static_cast<int>(Cards.size()); card++) {
        cout << Cards[card].toStringShort() << endl;
    }
}

// 3f)

void CardDeck::shuffle() {
    srand(time(nullptr));
    for (int i = 0; i < static_cast<int>(Cards.size()); i++) {
        swap(i, rand() % 52);
    }
}

// 3g)

Card CardDeck::drawCard() {
    Card card = Cards.back();
    Cards.pop_back();
    return card;
}