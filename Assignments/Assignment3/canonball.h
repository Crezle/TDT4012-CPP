// 1a)

double acclY();

// 1b)

double velY(double initVelocityY, double time);

// 1c)

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

// 1d)

void printTime(double time);

// 1e)

double flightTime(double initVelocityY);

// 4a)

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

// Til sjekk av vektor

void vPrint(vector<double> v);

// 4b)

double getDistanceTraveled(double velocityX, double velocityY);

// 4c)

double targetPractice(double distanceToTarget, double velocityX, double velocityY);