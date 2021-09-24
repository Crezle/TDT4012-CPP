#pragma once
#include "std_lib_facilities.h" //Brukes for å sjekke syntax-errors
#include "Graph.h"
#include "Simple_window.h"
#include "oppgave1.h"
#include "oppgave2.h"
#include "oppgave3.h"
#include "oppgave4.h"


using namespace Graph_lib;

// a)

// Gjort!

// b) , c) and d)

void createWin() {
    Simple_window win{Point{100,100},750,750,"Pythagoras"};
    
    Polygon rightTriangle{};
    rightTriangle.add(Point{300,300});
    rightTriangle.add(Point{300,500});
    rightTriangle.add(Point{450,500});
    rightTriangle.set_fill_color(Color::black);
    win.attach(rightTriangle);

    Polygon leftSquare{};
    leftSquare.add(Point{300,300});
    leftSquare.add(Point{300,500});
    leftSquare.add(Point{100,500});
    leftSquare.add(Point{100,300});
    leftSquare.set_fill_color(Color::green);
    win.attach(leftSquare);

    Polygon bottomSquare{};
    bottomSquare.add(Point{300,500});
    bottomSquare.add(Point{450,500});
    bottomSquare.add(Point{450,650});
    bottomSquare.add(Point{300,650});
    bottomSquare.set_fill_color(Color::red);
    win.attach(bottomSquare);

    Polygon hypoSquare{};
    hypoSquare.add(Point{450,500});
    hypoSquare.add(Point{300,300});
    hypoSquare.add(Point{500,150});
    hypoSquare.add(Point{650,350});
    hypoSquare.set_fill_color(Color::blue);
    win.attach(hypoSquare);

    win.wait_for_button();
}



