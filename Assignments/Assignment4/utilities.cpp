#include "utilities.h"

// 1b)

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// 1d)

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

// 1e)

void swapNumbers(int& a, int& b) {
    int b_temp = a;
    a = b;
    b = b_temp;
}

// Hvis vi ikke hadde brukt referanser, men heller returnerte verdier måtte vi
// også forsikret oss om at verdiene som ble returnert ble satt inn i riktige
// variabler. Å bruke referanser gjør det enklere ved at vi direkte bytter om variablene
// skrevet inn i funksjonen.

// 2b)

void printStudent(Student s) {
    cout << "Student name:  " << s.name << endl;
    cout << "Study program: " << s.studyProgram << endl;
    cout << "Student age:   " << s.age << endl;
}

// 2c)

bool isInProgram(Student s, string st) {
    if (s.studyProgram == st) {
        return true;
    } 
    else {
        return false;
    }
}

// 3b)

string randomizeString(int length, char lower, char upper) {
    srand(static_cast<unsigned int>(time(nullptr)));
    string ourString;
    int diff = static_cast<int>(upper) - static_cast<int>(lower);
    for (int i = 0; i < length; i++) {
        char randChar = 'A' + rand() % (diff);
        ourString += randChar;
    }
    return ourString;
}

// 3f)

string readInputToString(char lower, char upper, int n) {
    char input;
    char INPUT;
    char LOWER = toupper(lower);
    char UPPER = toupper(upper);
    int nLower = static_cast<int>(LOWER);
    int nUpper = static_cast<int>(UPPER);
    int nInput;
    string output;
    while (static_cast<int>(output.length()) < n) {
        cout << "Write a character between " << lower << " and " << upper << endl;
        cin >> input;
        INPUT = toupper(input);
        nInput = static_cast<int>(INPUT);
        if ((nInput <= nUpper) && (input >= nLower)) {
            output += input;
            cout << "Current string generated: " << output << endl;
        }
        else {
            cout << "Invalid character, please try again." << endl;
        }
    }
    return output;
}

// 3g)

int countChar(string s, char c) {
    vector<char> v(s.begin(),s.end());
    int charCount = 0;
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (v[i] == c) {
            charCount += 1;
        }
    }
    return charCount;
}

