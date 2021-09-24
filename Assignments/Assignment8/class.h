#pragma once
#include "std_lib_facilities.h"

// 1a)

class Car {
private:
    int freeSeats;
public:
    Car(int freeSeats);
    bool hasFreeSeats() const; //God vane for funksjoner som ikke endrer variabler.
    void reserveFreeSeat();
};

// 2a og c)

class Person {
private:
    string name;
    string email;
    Car* car; //Bruker peker for å vise at en "Person" ikke har en bil
public:
    Person(string name, string email, Car* car = nullptr);
    string getName() const;
    void setName(string newName);
    string getEmail() const;
    void setEmail(string newEmail);
    Car* getCar() const;
    bool hasAvailableSeats() const;
    friend ostream& operator<<(ostream& o, const Person p);
};