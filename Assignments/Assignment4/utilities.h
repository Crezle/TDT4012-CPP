#include "std_lib_facilities.h"

// 1b)

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

// 1d)

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

// 1e)

void swapNumbers(int&a, int&b);

// 2a)

struct Student{
    string name;
    string studyProgram;
    int age;
};

// 2b)

void printStudent(Student s);

// 2c)

bool isInProgram(Student s, string st);

// 3b)

string randomizeString(int length, char lower, char upper);

// 3f)

string readInputToString(char lower, char upper, int n);

// 3g)

int countChar(string s, char c);