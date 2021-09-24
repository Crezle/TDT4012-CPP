#pragma once
#include "std_lib_facilities.h" //Brukes for å sjekke syntax-errors
#include "oppgave1.h"
#include "oppgave2.h"
#include "oppgave3.h"

// a)

double discriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}

// b)

void printRealRoots(double a, double b, double c) {
    double d{discriminant(a,b,c)};
    if (d > 0) {
        double sol1{(-b + sqrt(d)) / (2*a)};
        double sol2{(-b - sqrt(d)) / (2*a)};
        cout << "Ligningen har 2 reele losninger: " << sol1 << " og " << sol2 << endl;
    }
    else if (d == 0) {
        double sol{(-b) / (2*a)};
        cout << "Ligningen har 1 reel losning: " << sol << endl;
    }
    else if (d < 0) {
        cout << "Ligningen har ingen reele losninger" << endl;
    }
}

// c)

void solveQuadraticEquation() {
    double a{};
    double b{};
    double c{};
    
    cout << "Skriv inn 'a' verdien i ligningen: " << endl;
    cin >> a;
    cout << "Skriv inn 'b' verdien i ligningen: " << endl;
    cin >> b;
    cout << "Skriv inn 'c' verdien i ligningen: " << endl;
    cin >> c;

    printRealRoots(a,b,c);
}

// d)

void createMenu3() {
    int ans{1};
	while (ans != 0) {
		cout << "Velg en funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO" << endl;
        cout << "4) Lag en gangetabell" << endl;
        cout << "5) Finn losninger pa andregradsuttrykk" << endl;
		cout << "Angi valg (0-5): ";
		cin >> ans;
		cout << endl;

		if (ans == 1) {
			inputIntegersAndPrintSum();
			cout << endl;
		}
		else if (ans == 2) {
			SumOfInputs();
			cout << endl;
		}
		else if (ans == 3) {
			NOKtoEUR();
			cout << endl;
		}
        else if (ans == 4) {
            multTable();
            cout << endl;
        }
        else if (ans == 5) {
            solveQuadraticEquation();
            cout << endl;
        }
	}
}

// e)

// Testet den i oppgave d), så det er bare å sjekke dens linje i "main.cpp".