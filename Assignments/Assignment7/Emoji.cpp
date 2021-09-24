#include "Emoji.h"
#include "Simple_window.h"
#include <cmath>
#include <iostream>


using namespace std;

using namespace Graph_lib;

const double pi = acos(0)*2;

// 3b og c)

Face::Face(Point c, int r): C(c, r) {
    C.set_fill_color(Color::yellow);
}

// 3d)

void Face::attach_to(Graph_lib::Window& win) {
    win.attach(C);
}

// 4a)

EmptyFace::EmptyFace(Point c, int r): 
    Face(c, r), 
    eye1(Point{c.x - r/3, c.y - r/4}, r/6), 
    eye2(Point{c.x + r/3, c.y - r/4}, r/6),
    eyeB1(Point{c.x - r/3, c.y - r/4}, r/10),
    eyeB2(Point{c.x + r/3, c.y - r/4}, r/10) {

    eye1.set_fill_color(Color::white); 
    eye2.set_fill_color(Color::white);
    eye1.set_color(Color::black); 
    eye2.set_color(Color::black);
    eyeB1.set_fill_color(Color::black); 
    eyeB2.set_fill_color(Color::black);
}

// 4b)

void EmptyFace::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(eye1);
    win.attach(eye2);
    win.attach(eyeB1);
    win.attach(eyeB2);
}

// 5)

Silent::Silent(Point c, int r): 
    EmptyFace(c, r),
    mouth(Point{c.x, c.y + r/3}, r, 1, 0, 180) {
    
    mouth.set_color(Color::black);
    }

void Silent::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

Sad::Sad(Point c, int r): 
    EmptyFace(c, r),
    mouth(Point{c.x, c.y + r/2}, r, 2*r/3, 0, 180) {
    
    mouth.set_color(Color::black);
    }

void Sad::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

Sus::Sus(Point c, int r): EmptyFace(c, r) {
    mouth.add(Point{c.x - r/2, c.y + r/3});
    mouth.add(Point{c.x - r/3, c.y + r/2});
    mouth.add(Point{c.x, c.y + 3*r/5});
    mouth.add(Point{c.x + r/3, c.y + r/2});
    mouth.add(Point{c.x + r/2, c.y + r/3});
    mouth.set_color(Color::black);
    mouth.set_fill_color(Color::black);
}

void Sus::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

Evil::Evil(Point c, int r): EmptyFace(c, r),
    mouth(Point{c.x, c.y + r/3}, r, r/2, -180, 0),
    brow1(Point{c.x - r/3, c.y - r/2}, r/4, r/12, -45, 135),
    brow2(Point{c.x + r/3, c.y - r/2}, r/4, r/12, 45, 225) {
    
    mouth.set_color(Color::black);
    brow1.set_color(Color::black);
    brow2.set_color(Color::black);
}

void Evil::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
    win.attach(brow1);
    win.attach(brow2);
}

Crying::Crying(Point c, int r): EmptyFace(c, r), 
    brow1(Point{c.x - r/3, c.y - r/4}, 55*r/100, 55*r/100, 10, 80),
    brow2(Point{c.x + r/3, c.y - r/4}, 55*r/100, 55*r/100, 100, 170) {

    mouth.add(Point{c.x - r/2, c.y + r/4 - r/8});
    mouth.add(Point{c.x - r/3, c.y + r/2 - r/8});
    mouth.add(Point{c.x - r/4, c.y + r*3/5 - r/8});
    mouth.add(Point{c.x, c.y + r*7/10 - r/8});
    mouth.add(Point{c.x + r/4, c.y + r*3/5 - r/8});
    mouth.add(Point{c.x + r/3, c.y + r/2 - r/8});
    mouth.add(Point{c.x + r/2, c.y + r/4 - r/8});
    mouth.set_color(Color::black);
    mouth.set_fill_color(Color::black);

    teeth.add(Point{c.x - r/2, c.y + r/4 - r/8});
    teeth.add(Point{c.x - 5*r/12, c.y + 3*r/8 - r/8});
    teeth.add(Point{c.x + 5*r/12, c.y + 3*r/8 - r/8});
    teeth.add(Point{c.x + r/2, c.y + r/4 - r/8});
    teeth.set_color(Color::black);
    teeth.set_fill_color(Color::white);

    brow1.set_color(Color::dark_red);
    brow2.set_color(Color::dark_red);
}

void Crying::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
    win.attach(brow1);
    win.attach(brow2);
    win.attach(teeth);
}

Vector_ref<Emoji> v() {
	Vector_ref<Emoji> v;
	static Silent a(Point{200,300}, 50);
    static Sad b(Point{400,300}, 50);
    static Sus c(Point{600,300}, 50);
    static Evil d(Point{800,300}, 50);
    static Crying e(Point{1000,300}, 50);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	return v;
}

void printEmojis(Graph_lib::Window& win, Vector_ref<Emoji> v) {
    for (int i = 0; i < v.size(); i++) {
        v[i].attach_to(win);
    }
}