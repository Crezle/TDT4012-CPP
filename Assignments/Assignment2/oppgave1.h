#pragma once

// a)

void inputAndPrintInteger() {
    int h{};
    cout << "Skriv inn et tall: ";
    cin >> h;
    
    cout << "Du skrev: " << h << endl;
}

// b)

int inputInteger() {
    int h{};
    cout << "Skriv inn et tall: ";
    cin >> h;
    
    return h;
}

// c)

void inputIntegersAndPrintSum() {
    int h1{inputInteger()};
    int h2{inputInteger()};
    int sum{h1+h2};
    
    cout << "Summen av tallene: " << sum << endl;
}

// d) 

// For å regne ut sum trenger vi selve verdiene vi skal operere med,
// funksjonen i a) etterlater seg ingen verdier og er derfor ubrukelig
// i dette tilfellet. Funksjonen i b) returnerer derimot verdiene vi trenger
// for å regne ut en sum.

// e)

bool isOdd(int number) {
    if (number%2 == 1) {
        return true;
    } 
    else {
        return false;
    }
}

// f)

void printHumanReadableTime(int s) {
    int hrs{s / 3600};
    int min{(s % 3600) / 60};
    int sec{s % 60};

    cout << hrs << " timer, " << min << " minutter, " << sec << " sekunder." << endl;
}