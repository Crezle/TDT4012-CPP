#include "animal.h"
#include "Graph.h"

using namespace Graph_lib;

Animal::Animal(string n, int a): name{n}, age{a} {}

string Animal::toString() {
    return "Animal: " + name + ", " + to_string(age);
}

Cat::Cat(string n, int a): Animal(n, a) {}

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age);
}

Dog::Dog(string n, int a): Animal(n, a) {}

string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age);
}

/* ostream& operator<<(ostream &o, Animal a) {
    cout << << a.age << a.name << "\n";
} */

void testAnimal(Vector_ref<Animal> v) {
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        cout << v[i].toString() << "\n";
    }
}

