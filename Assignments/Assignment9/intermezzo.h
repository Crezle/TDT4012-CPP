#pragma once
#include <iostream>
#include <array>

using namespace std;

// 3b, 3c og 3d)

class Dummy {
public:
    int *num;
    Dummy();
    Dummy(const Dummy &d);
    ~Dummy();
    Dummy operator=(Dummy d);
};

void dummyTest();