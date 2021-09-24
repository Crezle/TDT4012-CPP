#pragma once
#include "std_lib_facilities.h" //Brukes for å sjekke syntax-errors
#include "oppgave1.h"

// a)

void SumOfInputs() {
    cout << "How many inputs do you want the sum of?: " << endl;
    int t{};
    cin >> t;
    int s{};

    for (int i{}; i < t; i++) {
        int ans{};
        cout << "Enter an integer: " << endl;
        cin >> ans;
        s += ans;
    }

    cout << "The sum of your answers is: " << s << endl;
}

// b)

void SumUntilStop() {
    int s{};
    int i{1};
    while (i != 0) {
        cout << "Enter an integer: " << endl;
        cin >> i;
        s += i;
    }

    cout << "The sum of your answers is: " << s << endl;
}

// c)

// En For-løkke er godt egnet for første oppgave, ettersom antall iterasjoner
// bestemmes FØR løkken starter, mens den andre oppgaven bestemmes løkken 
// stoppes basert på hva som skjer UNDER løkken, som betyr at en while-løkke
// er godt egnet her, ettersom de repeterer frem til kravet for repitisjon brytes.

// d)

double inputDouble() {
    double h{};
    cout << "Skriv inn et tall: ";
    cin >> h;
    
    return h;
}

// e)

void NOKtoEUR() {
    double NOK{inputDouble()};
    while (NOK < 0) {
        cout << "Beløpet kan ikke være negativt, vennligst prøv på nytt." << endl;
        NOK = inputDouble();
    }
    
    double EUR{NOK*9.75};

    cout << setprecision(2) << fixed << EUR << endl;
}

// f)

// Det kan hende at man har antall kroner i desimaltall, og er derfor
// viktig å ta hensyn til desimalene og konverte de til euro også.
// Ettersom oppgaven ber om å skrive ut til skjermen, trenger vi ikke
// å returnere en verdi. Derfor setter vi den som en void type.