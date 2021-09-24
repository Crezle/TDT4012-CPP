#define _USE_MATH_DEFINES
#include "std_lib_facilities.h"
#include "canonball.h"
#include <cmath>

// 2a)

double acclY() {
    return -9.81;
}

// 2b)

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
}

// 2c)

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time;
}

double posY(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity * time + (acclY() * pow(time,2)) / 2;
}

// 2d)

void printTime(double time) {
    int hours = static_cast<int>(time) / 3600;
    int min = (static_cast<int>(time) % 3600) / 60;
    double sec = time - min * 60 - hours * 3600;

    cout << hours << " hours, " << min << " minutes, " << sec << " seconds."  << endl;
}

// 2e)

double flightTime(double initVelocityY) {
    return -2 * initVelocityY / acclY();
}

// 4a)

double getUserInputTheta() {
    cout << "Enter angle here: " << endl;
    double theta;
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    cout << "Enter absolute velocity: " << endl;
    double absVelocity;
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg) {
    return deg * M_PI / 180;
}

double getVelocityX(double theta, double absVelocity) {
    double rTheta = degToRad(theta);
    return absVelocity * cos(rTheta);
}

double getVelocityY(double theta, double absVelocity) {
    double rTheta = degToRad(theta);
    return absVelocity * sin(rTheta);
}

vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> VelocityVector(0);
    VelocityVector.push_back(getVelocityX(theta, absVelocity));
    VelocityVector.push_back(getVelocityY(theta, absVelocity));
    return VelocityVector;
}

// Til sjekk av vektor

void vPrint(vector<double> v) {
    for (double i = 0.0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
}

// 4b)

double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    double DistanceTraveled = posX(0.0, velocityX, time);
    return DistanceTraveled;
}

// 4c)

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    double error = distanceToTarget - distanceTraveled;
    return error;
}