#include <chrono>
#include <thread>
#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "vehicle.h"

#include "utilities.h"

int main() {
	auto win = std::make_unique<Fl_Double_Window>(screenWidth, screenHeight, "NASCAR");
	win->color(FL_WHITE);

	// Instansier nye objekt mellom dei to etterfølgjande linjene.
	// -----------------------------------------------------------------------------
	PlayerVehicle p(vehicleRadius + 20 ,vehicleRadius + 20);
	// -----------------------------------------------------------------------------

	win->end();
	win->show();

	auto nextDrawing = std::chrono::steady_clock::now();

	while (win->shown())
	{
		// Sov til neste teikning
		std::this_thread::sleep_until(nextDrawing);
		nextDrawing += std::chrono::microseconds(1'000'000 / 60);

		Fl::check();	// Handterar input
		Fl::redraw();	// Kallar draw
	}
}