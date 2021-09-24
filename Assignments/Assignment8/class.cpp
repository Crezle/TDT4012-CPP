#include "class.h"

// 1b og c)

Car::Car(int freeSeats): 
freeSeats{freeSeats} 
{};

bool Car::hasFreeSeats() const{
    if (freeSeats > 0) {
        return true;
    }
    else {
        return false;
    }
}

void Car::reserveFreeSeat() {
    if (freeSeats > 0) {
        freeSeats--;
        cout << "A seat has been reserved!\n";
    }
    else {
        cout << "No seats were available, and therefore a seat was not reserved.\n";
    }
}

// 2b)

Person::Person(string name, string email, Car* car): 
name{name},
email{email},
car{car} 
{};

string Person::getName() const {
    return name;
}

void Person::setName(string newName) {
    name = newName;
}

string Person::getEmail() const {
    return email;
}

void Person::setEmail(string newEmail) {
    email = newEmail;
}

Car* Person::getCar() const {
    return car;
}

// 2c)

bool Person::hasAvailableSeats() const{
    if (car) {
        return car->hasFreeSeats();
    }
    else {
        return false;
    }
}

// 2d)

ostream& operator<<(ostream& o, const Person p) {
    o << "Name: " << p.name << '\n';
    o << "Email: " << p.email << '\n';
    return o;
}

// Person burde være constant i dette tilfellet pga. ingenting skal endres før den skrives ut.
// Hvis vi skulle ta inn variabler, vil vi ikke ha const, ettersom de muligens skal endres senere.