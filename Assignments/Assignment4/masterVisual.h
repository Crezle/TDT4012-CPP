#pragma once
#include "GUI.h"
using namespace Graph_lib;

constexpr int winW = 500; // velg vindu bredde
constexpr int winH = 700; // velg vindu hoyde

constexpr int padX = winW / (2*5+1);      // velg x skalering
constexpr int padY = winH / (2*12+1);      // velg y skalering
constexpr int radCircle = padX / (2*4); // velg sirkel radius

constexpr int btnW = padX;
constexpr int btnH = padY;
constexpr Point upperLeftCornerBtn = Point{winW - padX - btnW, padY};

constexpr int inBoxW = winW - 3 * padX - btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX, padY};

class MastermindWindow : public Window
{
public:
    MastermindWindow(Point xy, int w, int h, const string &title);

    static void cb_guess(Address, Address pw)
    {
        reference_to<MastermindWindow>(pw).newGuess();
    }

    Vector_ref<Rectangle> vr;
    Vector_ref<Circle> vc;

    string getInput(unsigned int n, char lower, char upper);

    void redraw()
    {
        Fl::redraw();
        Fl::wait();
    }

private:
    string wait_for_guess();
    void newGuess() { button_pressed = true; }
    bool button_pressed;
    Button guessBtn;
    In_box guess;
};

void addGuess(MastermindWindow &mwin, const string code, const int size, const char startLetter, const int round);
void hideCode(MastermindWindow &mwin, const int size);

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter,
                 const int size, const int round);
