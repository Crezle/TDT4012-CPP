#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <list>

class Person {
private:
    std::string firstname;
    std::string surname;
public:
    Person(std::string fname, std::string sname);
    std::string getFirstname() const;
    void setFirstname(std::string name);
    std::string getSurname() const;
    void setSurname(std::string name);
    friend std::ostream& operator<<(std::ostream& o, Person p);
};

void insertOrdered(std::list<Person> &l, const Person& p);

void showList(std::list<Person> l);