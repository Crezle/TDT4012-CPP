#include "tests.h"
#include "utilities.h"

// 1c)

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

// 1d)

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations << endl;
}


// 3a, c, d og h)

void testString() {
    string grades = randomizeString(8,'A','F');
    cout << grades << endl;

    int diff = 5;
    vector<int> gradeCount(0);
    int count;
    char grade;
    for (int i = 0; i <= diff; i++) {
        grade = static_cast<char>('A' + i);
        count = countChar(grades,grade);
        gradeCount.push_back(count);
    }

    int gradeSum = 0;
    for (int c = 0; c < static_cast<int>(gradeCount.size()); c++) {
        gradeSum += gradeCount[c] * (5 - c);
    }
    float average = gradeSum / 8.0;

    cout << "Average grade is: " << average << endl;
}
