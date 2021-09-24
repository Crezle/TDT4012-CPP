#pragma once
#include "std_lib_facilities.h" //Brukes for å sjekke syntax-errors
#include "oppgave1.h"
#include "oppgave2.h"

// a)

void createMenu() {
    int ans{1};
	while (ans != 0) {
		cout << "Velg en funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO." << endl;
		cout << "Angi valg (0-3): ";
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
	}
}

// b)

void multTable() {
    cout << "Hoyde?: ";
	int h{};
	cin >> h;

	cout << "Bredde?: ";
	int w{};
	cin >> w;

	string l(w*5, '|');

	for (int a{1}; a <= h; a++) {
		cout << l << endl;
		for (int b{1}; b <= w; b++) {
			cout << '|' << setw(3) << a*b << '|';
		}
		cout << endl;
	}
	cout << l << endl;
}

void createMenu2() {
    int ans{1};
	while (ans != 0) {
		cout << "Velg en funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO." << endl;
        cout << "4) Lag en gangetabell." << endl;
		cout << "Angi valg (0-4): ";
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
	}
}