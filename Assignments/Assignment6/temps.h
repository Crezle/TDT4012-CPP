#include "std_lib_facilities.h"

// 4a)

struct Temps {
    double max;
    double min;
};

// 4b)

istream& operator>>(istream& is, Temps& t);

// 4c)

vector<Temps> readTemps(string textfile);

void printVector(vector<Temps> t);

// 4d)

void tempStats(vector<Temps> t);