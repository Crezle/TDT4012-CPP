#include "intermezzo.h"

// 3a)

/* 
Første omgang:
    a blir satt lik 4.
    Pekeren til b blir satt lik pekeren til a.
    c sin peker blir satt lik a.
    Dermed deler a, b og c samme peker, som peker mot addressen med verdien 4.

Andre omgang:
    Alle pekerene peker til samme addresse, så ved *b.num settes verdien i addressen til 3,
    og deretter settes den til 5.
    Så a, b og c vil gi 5 ved dereferering.
*/

// 3b)

Dummy::Dummy() {
    num = new int{0};
}



Dummy::~Dummy() {
    delete num;
}

void dummyTest() {
Dummy a;
*a.num = 4;
Dummy b{a};
Dummy c;
c = a;
cout << "a: " << *a.num << '\n';
cout << "b: " << *b.num << '\n';
cout << "c: " << *c.num << '\n';
*b.num = 3;
*c.num = 5;
cout << "a: " << *a.num << '\n';
cout << "b: " << *b.num << '\n';
cout << "c: " << *c.num << '\n';
}

// 3c)

Dummy::Dummy(const Dummy &d) {
    num = new int{*d.num};
}

// 3d)

Dummy Dummy::operator=(Dummy d) {
    num = new int{*d.num};
    return *this;
}

// SVAR FOR 3b)
// Programmet stemte overens med forventningene, programmet kræsjer fordi vi prøver å 
// fjerne verdier for samme peker flere ganger. Og dette kræsjer fordi vi allerede har
// slettet verdien i addressen.

// SVAR FOR 3c)
// Programmet printer forsatt det samme ut i første omgang, som er intensjonen.
// Men i andre omgang så ser vi at b printes ut annerledes, og det er fordi b har sin egen
// peker for sin verdi. a og c deler fortsatt samme peker.

// 4a)

