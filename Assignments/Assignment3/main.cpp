#include "std_lib_facilities.h"
#include "canonball.h"
#include "utilities.h"

int main()
{
// 1a og 2a)

	/* cout << "Oppgave 1 og 2a)" << endl;
	cout << acclY() << endl;
	cout << endl; */

// 1b og 2b)

	/* cout << "Oppgave 1 og 2b)" << endl;
	cout << velY(25.0, 0.0) << endl;
	cout << velY(25.0, 2.5) << endl;
	cout << velY(25.0, 5.0) << endl;
	cout << endl; */

// 1c og 2c)

	/* cout << "Oppgave 1 og 2c)" << endl;
	cout << posX(0.0, 50.0, 0.0) << endl;
	cout << posX(0.0, 50.0, 2.5) << endl;
	cout << posX(0.0, 50.0, 5.0) << endl;
	cout << endl;

	cout << posY(0.0, 25.0, 0.0) << endl;
	cout << posY(0.0, 25.0, 2.5) << endl;
	cout << posY(0.0, 25.0, 5.0) << endl;
	cout << endl; */

// 1d og 2d)

	/* cout << "Oppgave 1 og 2d)" << endl;
	printTime(10000); */

// 1e og 2e)

	/* cout << "Oppgave 1 og 2e)" << endl;
	cout << flightTime(25.0) << endl;
	cout << endl; */

// 4a)

	/* cout << "Oppgave 4a)" << endl;
	double theta = getUserInputTheta();
	cout << theta << endl;
	cout << endl;

	double AbsVelocity = getUserInputAbsVelocity();
	cout << AbsVelocity << endl;
	cout << endl;

	cout << "Converted degrees to radians." << endl;
	double rTheta = degToRad(theta);
	cout << rTheta << endl;
	cout << endl;

	cout << "X-Velocity." << endl;
	cout << getVelocityX(theta, AbsVelocity) << endl;
	cout << endl;

	cout << "Y-Velocity." << endl;
	cout << getVelocityY(theta, AbsVelocity) << endl;
	cout << endl; */

	/* cout << "Velocity vector." << endl;
	vector<double> v = getVelocityVector(30, 75);
	vPrint(v);
	cout << endl; */

	// 4b)

	/* cout << "Oppgave 4b)" << endl;
	cout << "Distance traveled." << endl;
	cout << getDistanceTraveled(100,100) << endl;
	cout << endl; */

	// 4c)

	/* cout << "Oppgave 4c)" << endl;
	cout << "Distance from target" << endl;
	cout << targetPractice(3000, 100, 100) << endl;
	cout << endl; */

	// 5a, b og c) (Vi kjører srand mellom hver kjøring slik at det blir mest tilfeldig)

	/* cout << "Oppgave 5a, b og c)" << endl;
	cout << randomWithLimits(1, 100) << endl;
	cout << endl; */

	// 5d)

	playTargetPractice();

	keep_window_open();
}
