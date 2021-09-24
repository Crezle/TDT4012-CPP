#pragma once

#include <vector>
#include <string>
#include <iostream>

/* template<typename T>
T maximum(T n1, T n2);

template<typename T>
void shuffle(std::vector<T>& v); */

template<typename T>
T maximum(T n1, T n2) {
    if (n1<n2) {
        return n2;
    }
    else {
        return n1;
    }
}

template<typename T>
void shuffle(std::vector<T>& v) {
    int randNum;
    T temp;
    for (int i = 0; i < v.size(); i++) {
        randNum = rand() % v.size();
        temp = v[i];
        v[i] = v[randNum];
        v[randNum] = temp;
    }
}