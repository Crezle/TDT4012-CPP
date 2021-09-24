#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button
{
	bool isMine = false;
	Cell state = Cell::closed;

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
public:
	Tile(Point pos, int size, Graph_lib::Callback cb)
		:Button{pos, size, size, "", cb} {};
	
	Cell getState() const {return state; };
	bool getisMine() const;
	void setisMine(bool setMine);
	void open();
	void flag();
	void setAdjMines(int n);
};
