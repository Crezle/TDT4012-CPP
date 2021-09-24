#pragma once
#include "std_lib_facilities.h" //Brukes for å sjekke syntax-errors
#include "oppgave1.h"
#include "oppgave2.h"
#include "oppgave3.h"
#include "oppgave4.h"
#include "oppgave5.h"
// a)


vector<int> calculateBalance(int s, int r, int yrs) {
    vector<int> totSaldo(0);
    double prevSaldo = static_cast<double>(s);

    for (int y{0}; y <= yrs; y++) {
        
        double saldo = prevSaldo*pow(1+r/100.0,y);
        prevSaldo = saldo;
        totSaldo.push_back(saldo);
    }
    return totSaldo; //Her har vi regnet med renters renter
}

// Funksjon for å kontrollere om vektoren er riktig
void vPrint(vector<int> a) {
		for (int i{0}; i < a.size(); i++) {
			cout << a.at(i) << ", ";
		}
	}

// b)

void printBalance(vector<int> a) {
    cout << setw(3) << "Ar" << ":" << setw(7) << "Saldo" << ":" << endl;
    for (int i{0}; i < a.size(); i++) {
        cout << setw(3) << i << setw(8) << a.at(i) << endl;
    }
}

// c)

void createMenu4() {
    int ans{1};
	while (ans != 0) {
		cout << "Velg en funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO" << endl;
        cout << "4) Lag en gangetabell" << endl;
        cout << "5) Finn losninger pa andregradsuttrykk" << endl;
        cout << "6) Regn ut renter etter ar" << endl;
        cout << endl;
		cout << "Angi valg (0-6): ";
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
        else if (ans == 6) {
            int s;
            int r;
            int yrs;
            cout << "Hvor stor er saldoen?: " << endl;
            cin >> s;
            cout << "Hvor stor er renten?: " << endl;
            cin >> r;
            cout << "Hvor mange ar fremover vil du se?: " << endl;
            cin >> yrs;

            printBalance(calculateBalance(s,r,yrs));
            cout << endl;
        }
	}
}
