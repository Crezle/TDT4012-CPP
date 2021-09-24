#define RAND_MAX
#include "std_lib_facilities.h"
#include "utilities.h"
#include "canonball.h"
#include "cannonball_viz.h"
#include <cstdlib>

// 5a, b og c)

int randomWithLimits(int lowerLimit, int upperLimit) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int nums = upperLimit - lowerLimit + 1;
    int rInt = rand() % nums + lowerLimit;
    return rInt; 
}

// 5d og e)

void playTargetPractice() {
    cout << "Welcome to playTargetPractice game by Christian Le!" << endl;
    cout << endl;
    cout << "Try to hit the random placed target within 10 turns." << endl;
    cout << "Your cannon's strength and angle are adjustable each turn." << endl;
    cout << endl;

    int t = 1;
    int randDistance = randomWithLimits(100, 1000);
    double theta;
    double absVelocity;
    vector<double> v;
    double dFromTarget;
    double timeInAir;

    cout << "The target is " << randDistance << " meters from you" << endl;
    cout << endl;
 
    while (t <= 10) {
        cout << "Turn number " << t << endl;
        cout << endl;
        theta = getUserInputTheta();
        cout << endl;
        absVelocity = getUserInputAbsVelocity();
        cout << endl;
        
        v = getVelocityVector(theta, absVelocity);
        dFromTarget = targetPractice(randDistance, v.at(0), v.at(1));
        timeInAir = flightTime(v.at(1));
    
        if (dFromTarget > 5) {
            cannonBallViz(randDistance, 1000, v.at(0), v.at(1), 100);
            cout << "Your shot didn't go far enough!" << endl;
            cout << "You hit " << dFromTarget << " meters from your target." << endl;
            cout << "The cannonball spent " << timeInAir << " seconds in the air" << endl;
            cout << endl;
            t+=1;
        }

        else if (dFromTarget < -5) {
            cannonBallViz(randDistance, 1000, v.at(0), v.at(1), 100);
            cout << "Your shot went too far!" << endl;
            cout << "You hit " << dFromTarget * -1 << " meters from your target." << endl;
            cout << "The cannonball spent " << timeInAir << " seconds in the air" << endl;
            cout << endl;
            t+=1;
        }

        else {
            cannonBallViz(randDistance, 1000, v.at(0), v.at(1), 100);
            cout << "Your shot was perfect!" << endl;
            cout << "You hit 5 meters within your target in " << t << " turns, which means you won!" << endl;
            cout << "The cannonball spent " << timeInAir << " seconds in the air" << endl;
            cout << endl;
            t+=11;
        }
    }
    if (t <= 11) {
        cout << "Sorry, you did not make it in 10 turns. Better luck next time!" << endl;
    }
}

