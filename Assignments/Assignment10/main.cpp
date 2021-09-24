#include "MinesweeperWindow.h"

int main()
{
	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 5;

	Point startPoint{ 540,300 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();
}
