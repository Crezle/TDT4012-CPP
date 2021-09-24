#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window& win) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face: public Emoji {
protected:
	Circle C;
public:
	Face(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override = 0;
};

// 4a)

class EmptyFace: public Face {
protected:
	Circle eye1;
	Circle eye2;
	Circle eyeB1;
	Circle eyeB2;
public:
	EmptyFace(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override;
};

// 5)

class Silent: public EmptyFace {
private:
	Arc mouth;
public:
	Silent(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

class Sad: public EmptyFace {
private:
	Arc mouth;
public:
	Sad(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

class Sus: public EmptyFace {
private:
	Polygon mouth;
public:
	Sus(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

class Evil: public EmptyFace {
private:
	Arc mouth;
	Arc brow1;
	Arc brow2;
public:
	Evil(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

class Crying: public EmptyFace {
private:
	Polygon mouth;
	Polygon teeth;
	Arc brow1;
	Arc brow2;
public:
	Crying(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

Vector_ref<Emoji> v();

void printEmojis(Graph_lib::Window& win, Vector_ref<Emoji> v);
