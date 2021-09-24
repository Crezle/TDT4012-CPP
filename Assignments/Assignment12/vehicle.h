#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include "std_lib_facilities.h"
#include <tuple>
#include "utilities.h"
#include <FL/Enumerations.H> 

#define _USE_MATH_DEFINES
#include <math.h>



// 1a)

class Vehicle: public Fl_Widget {
protected:
    virtual pair<double, double> steer() const = 0;
    virtual void drawBody() const = 0;
    PhysicsState ps;
public:
    Vehicle(int x, int y);
    void draw() final;
};

class PlayerVehicle: public Vehicle {
protected:
    pair<double, double> steer() const override;
    void drawBody() const override;
public:
    PlayerVehicle(int x, int y);
};
