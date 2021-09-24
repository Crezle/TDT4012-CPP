#pragma once
#include "Window.h"
#include "Tile.h"

using namespace Graph_lib;
enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; //

// Minesweeper GUI
class MinesweeperWindow : public Graph_lib::Window
{
public:
	//storrelsen til hver tile
	static constexpr int cellSize = 50;
	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);
	int countFlags() const;
	void updateLeftovers();
private:

	const int width; //bredde i antall tiles
	const int height; //hoyde i antall tiles
	const int mines; //antall miner
	Text winText;
	Text loseText;
	Vector_ref<Tile> tiles; //vektor som inneholder alle tiles
	Point flagCountP = {cellSize*1,cellSize*(height+1)};

	//hoyde og bredde i piksler
	int Height() const { return height * cellSize; }
	int Width() const { return width * cellSize; }

	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;
	//tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;

	//Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x < Width() && xy.y >= 0 && xy.y < Height(); }
	//Returnerer en tile gitt et punkt
	Tile& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const Tile& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	//aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	//callback funksjon for tile knappene
	static void cb_click(Address, Address pw) { reference_to<MinesweeperWindow>(pw).click(); };
	void click();
};
