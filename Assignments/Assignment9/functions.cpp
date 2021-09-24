#include "functions.h"
#include <iostream>

using namespace std;

// 1a)

void fillInFibonacciNumbers(int result[], int length) {
    int n1 = 0;
    int n2 = 1;

    for (int i = 0; i < length; i++) {
        if (i == 0) {
            result[i] = n1;
        }
        else if (i == 1) {
            result[i] = n2;
        }
        else {
            result[i] = result[i-1] + result[i-2];
        }
    }
}

// 1b)

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "Array number " << i+1 << ": " << arr[i] << '\n';
    }
}

// 1c)

void createFibonacci() {
    int length; 
    cout << "How many fibonacci numbers do you want to generate?\n";
    cin >> length;
    int *myArray = new int[length];
    fillInFibonacciNumbers(myArray, length);
    printArray(myArray, length);
    delete[] myArray;
}

