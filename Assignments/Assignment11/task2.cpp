#include "task2.h"

Person::Person(std::string fname, std::string sname): firstname{fname}, surname{sname} {

}

std::string Person::getFirstname() const {
    return firstname;
}

std::string Person::getSurname() const {
    return surname;
}

void Person::setFirstname(std::string name) {
    firstname = name;
}

void Person::setSurname(std::string name) {
    surname = name;
}

std::ostream& operator<<(std::ostream& o, Person p) {
    o << p.firstname << " " << p.surname;
    return o;
}

void insertOrdered(std::list<Person> &l, const Person& p) {
    if (l.size() == 0) {
        l = {p};
        return;
    }
    else {
        std::list<Person>::iterator fnamePtr;
        std::list<Person>::iterator snamePtr;

        for (fnamePtr = l.begin(); fnamePtr != l.end(); fnamePtr++) {
            if (fnamePtr->getFirstname() > p.getFirstname()) {
                l.insert(fnamePtr, p);
                return;
            }
            else if (fnamePtr->getFirstname() == p.getFirstname()) {
                for (snamePtr = l.begin(); snamePtr != l.end(); snamePtr++) {
                    if (snamePtr->getSurname() >= p.getSurname()) {
                        l.insert(snamePtr, p);
                        return;
                    }
                }
            }
        }
        l.push_back(p);
    }
} 

void showList(std::list<Person> l) {
    std::list<Person>::iterator personPtr;
    for (personPtr = l.begin(); personPtr != l.end(); personPtr++) {
        std::cout << *personPtr << '\n';
    }
}