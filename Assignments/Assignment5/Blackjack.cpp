#include "Blackjack.h"

// 4)

Blackjack::Blackjack() { //Creates the game
    deck.clear();
    for (int suit = 0; suit < SUIT_SIZE; suit++) {
        for (int rank = 0; rank < RANK_SIZE; rank++) {
            deck.push_back(Card{Rank{rank+2},Suit{suit}});
        }
    }

    srand(time(nullptr)); //Shuffles the deck
    for (int i = 0; i < static_cast<int>(deck.size()); i++) {
        Card temp = deck[i];
        deck[i] = deck[rand() % 52];
        deck[rand() % 52] = temp;
    }

    for (int draws = 0; draws < 4; draws++) { //Gives the two first cards to player and dealer
        Card card = deck.back();
        deck.pop_back();
        if ((draws % 2) == 0) {
            dealerHand.push_back(card);
        }
        else {
            playerHand.push_back(card);
        }
    }
}

void Blackjack::drawCard() {
    for (int draws = 0; draws < 2; draws++) {
        Card card = deck.back();
        deck.pop_back();

        if ((draws % 2) == 0) {
            if (dealerValue() < 17) {
                dealerHand.push_back(card);
            }
            else {
                cout << "The dealer stopped drawing cards." << endl << endl;
            }
        }
        else {
            playerHand.push_back(card);
            cout << "You drew " << playerHand.back().getString() << endl << endl;
        }
    }
}

void Blackjack::handPrint() {
    cout << "You are currently holding these cards: " << endl << endl;
    for (int card = 0; card < static_cast<int>(playerHand.size()); card++) {
        cout << playerHand[card].getString() << endl;
    }
    cout << endl;
}

void Blackjack::dealerPrint() {
    cout << "The dealer held these cards: " << endl << endl;
    for (int card = 0; card < static_cast<int>(dealerHand.size()); card++) {
        cout << dealerHand[card].getString() << endl;
    }
    cout << endl;
    cout << "which has a total value of " << dealerValue() << endl << endl;
}

int Blackjack::handValue() {
    int hValue = 0;
    int aces = 0;
    for (int i = 0; i < static_cast<int>(playerHand.size()); i++) {
        int value = static_cast<int>(playerHand[i].getRank());
        if (value == 14) {
            aces += 1;
        }
        else if ((value < 14) && (value > 10)) {
            hValue += 10;
        }
        else {
            hValue += value;
        }
    }
    for (int j = 0; j < aces; j++) {
        if (j != (aces - 1)) {
            hValue += 1;
        }
        else if (hValue < 11) {
            hValue += 11;
        }
        else {
            hValue += 1;
        }
    }
    return hValue;
}

int Blackjack::dealerValue() {
    int hValue = 0;
    int aces = 0;
    for (int i = 0; i < static_cast<int>(dealerHand.size()); i++) {
        int value = static_cast<int>(dealerHand[i].getRank());
        if (value == 14) {
            aces += 1;
        }
        else if ((value < 14) && (value > 10)) {
            hValue += 10;
        }
        else {
            hValue += value;
        }
    }
    for (int j = 0; j < aces; j++) {
        if (j != (aces - 1)) {
            hValue += 1;
        }
        else if (hValue < 11) {
            hValue += 11;
        }
        else {
            hValue += 1;
        }
    }
    return hValue;
}

void Blackjack::printStatus() {
    handPrint();
    cout << "The value of your hand is: " << handValue() << endl << endl;
    string dealerTopCard = dealerHand[0].getString();
    cout << "The dealer's top card is " << dealerTopCard << endl;
    cout << "and holds a total of " << dealerHand.size() << " cards." << endl << endl;
}

char Blackjack::prompt() {
    char choice;
    cout << "Do you wish to draw another card? (Y/N)" << endl;
    cin >> choice;
    cout << endl;
    return choice;
}

void Blackjack::endGame() {
    int cardsDrawn = 0;
    while (dealerValue() < 17) {
        Card card = deck.back();
        deck.pop_back();
        dealerHand.push_back(card);
        cardsDrawn += 1;
    }
    cout << "The dealer drew an additional " << cardsDrawn << " card(s)." << endl;
    dealerPrint();
    cout << "which means you ";
    if (handValue() > dealerValue() || dealerValue() > 21) {  
        cout << "won!" << endl << endl;
    }
    else {
        cout << "lost, better luck next time!" << endl << endl;
    }
}

void playBlackjack() {
    Blackjack game;
	game.printStatus();
    char choice = game.prompt();

    while (choice == 'Y') {
        game.drawCard();
        if (game.handValue() > 21) {
            break;
        }
        game.printStatus();
        choice = game.prompt();
    }
    if (choice == 'N') {
        game.endGame();    
    }
    else if (game.handValue() > 21) {
        cout << "which means your cards had a value of " << game.handValue() << ". Therefore, you lost." << endl << endl;
    }
}
