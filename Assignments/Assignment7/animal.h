#include "std_lib_facilities.h"
#include "Graph.h"

using namespace Graph_lib;

// 1a)

/* Public-medlemmer kan nås/brukes av hvem som helst utenfor klassen.
Private-medlemmer kan kun nås innad i klassen, f.eks.: en funksjon i klassen,
mens en protected-medlem kan nås av enten en medlem innad i klassen eller 
en annen klasse (child-class) som er assosiert med den gjeldende klassen. */

// 1b)

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a);
    virtual string toString() = 0;
};

class Cat: public Animal{
public:
    Cat(string n, int a);
    string toString() override;
};

class Dog: public Animal{
public:
    Dog(string n, int a);
    string toString() override;
};

// 1c)

void testAnimal(Vector_ref<Animal> v);

