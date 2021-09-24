#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, (2+height)*cellSize, title}, width{width}, height{height}, mines{mines},
	winText{Point{width*cellSize/4,height*cellSize/4}, "You win"},
	loseText{Point{width*cellSize/4,height*cellSize/4}, "You lost"}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner (OPPGAVE 2A)
	srand(time(nullptr));
	int randPos;
	vector<int> minePos;
	while (static_cast<int>(minePos.size()) < this->mines) {
		randPos = rand() % static_cast<int>(tiles.size());
		if (!count(minePos.begin(), minePos.end(), randPos)) {
			minePos.push_back(randPos);
			tiles[randPos].setisMine(true);
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

// OPPGAVE 2B OG 2C)

void MinesweeperWindow::openTile(Point xy) {
	Tile& t = at(xy);
	if (t.getState() != Cell::closed) {
		return;
	}
	t.open();
	if (t.getisMine()) {
		for (Tile* ti: tiles) {
			if (ti->getisMine()) {
				ti->open();
			}
		} 
		loseText.set_font(Font::times_bold);
		loseText.set_font_size(60);
		loseText.set_color(Color::black);
		Graph_lib::Window::attach(loseText);
		return;
	}
	vector<Point> adj = adjacentPoints(xy);
	int adjMines = countMines(adj);
	if (adjMines) {
		t.setAdjMines(adjMines); 
	}
	else {
		for (Point p: adj) {
			openTile(p);
		}
	}

	for (Tile* check: tiles) { //If this passes, the game is won
		if (!check->getisMine() && check->getState() == Cell::closed) {
			return;
		}
	}
	for (Tile* check: tiles) {
		if (check->getState() != Cell::flagged) {
			check->flag();
		}
	}
	winText.set_font(Font::times_bold);
	winText.set_font_size(60);
	winText.set_color(Color::black);
	Graph_lib::Window::attach(winText);
	return;
}

void MinesweeperWindow::flagTile(Point xy) {
	at(xy).flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
	flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int numOfMines = 0;
	for (Point p: coords) {
		if (at(p).getisMine()) {
			numOfMines++;
		}
	}
	return numOfMines;
}

int MinesweeperWindow::countFlags() const{
	int f = 0;
	for (Tile* check: tiles) {
		if (check->getState() == Cell::flagged) {
			f++;
		}
	}
	return f;
}

void MinesweeperWindow::updateLeftovers() {
	string s = "There are " + to_string(mines - countFlags()) + " mines left.";
}