#include "vehicle.h"

// 1a)

Vehicle::Vehicle(int x, int y): Fl_Widget(10,10,10,10) {
    ps.x = x;
    ps.y = y;
    double angle;
}

// 1b) 1c) 2a)

void Vehicle::draw() {
    pair<double, double> s = steer();
    if (ps.x - vehicleRadius >= 0 && ps.x + vehicleRadius <= screenWidth && ps.y - vehicleRadius >= 0 && ps.y + vehicleRadius <= screenHeight) {
        ps.update(s.second, s.first);
    }
    else {
        ps.angle, ps.speed = 0;
        ps.x, ps.y = vehicleRadius + 20;
    }

    drawBody();
}

// 2a)

PlayerVehicle::PlayerVehicle(int x, int y): Vehicle(x, y) {}

void PlayerVehicle::drawBody() const {
    /* fl_draw_box(FL_FLAT_BOX, ps.x, ps.y, w, h, FL_RED); */
    fl_begin_line();
    fl_color(FL_DARK_YELLOW);
    fl_pie(ps.x, ps.y, vehicleRadius, vehicleRadius, 30 - ps.angle * 180 / M_PI, 330 - ps.angle * 180 / M_PI);
    fl_end_line();
}

// 2b)



// 2c)

pair<double, double> PlayerVehicle::steer() const {
    pair<double, double> command;
    
    switch(Fl::event_key()) {
        case FL_Left: command.first = -1;
        break;

        case FL_Right: command.first = 1;
        break;

        case FL_Up: command.second = 1;
        break;

        case FL_Down: command.second = -1;
        break;
    }

    if (ps.x < 0 || ps.x > screenWidth + vehicleRadius || ps.y < 0 || ps.y > screenHeight + vehicleRadius) {
        command.first, command.second = 0;
    }

    return command;
}
