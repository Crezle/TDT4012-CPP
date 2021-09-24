#include "std_lib_facilities.h"

int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    }
    else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

// b) er nederst i main-funksjonen

// c)

int fibonacci(int n) {
	int a{0};
	int b{1};
	cout << "Fibonacci numbers: " << endl;
	for ( int x{1}; x < n + 1; ++x ) {
		cout << x << ", " << b << endl;
		int temp{b};
		b += a;
		a = temp;
	}
	cout << "----" << endl;
	return b;
}

// d)

int squareNumberSum(int n) {
	int totalSum{0};
	for ( int i{0}; i < n; ++i ) {
		totalSum += (i * i);
		cout << (i * i) << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

// e)

void triangleNumbersBelow(int n) {
	int acc{1};
	int num{2};
	cout << "Triangle numbers below " << n << ":" << endl;
	while ( acc < n ) {
		cout << acc << endl;
		acc += num;
		++num;
	}
	cout << "" << endl;
}

// f)

bool isPrime(int n) {
	for ( int j{2}; j < n; ++j ) {
		if ( n % j == 0) {
			return false;
		}
	}
	return true; 
}

// g)

void naivePrimeNumberSearch(int n) {
	for ( int number{2}; number < n; ++number) {
		if (isPrime(number)) {
			cout << number << " is a prime" << endl;
		}
	}
}

// h)

int findGreatestDivisor(int n) {
	for ( int divisor{ n - 1 }; n > 0; divisor -= 1 ) {
		if ( n % divisor == 0) {
			return divisor;
		}
	}
}

// b)

int main() // Brukes for å teste koden
{
	cout << "Oppgave a)" << endl;
	cout << maxOfTwo(5, 6) << endl;
	cout << endl;

	cout << "Oppgave c)" << endl;
	cout << fibonacci(5) << endl;
	cout << endl;

	cout << "Oppgave d)" << endl;
	cout << squareNumberSum(3) << endl;
	cout << endl;

	cout << "Oppgave e)" << endl;
	triangleNumbersBelow(11);
	cout << endl;

	cout << "Oppgave f)" << endl;
	cout << isPrime(4) << endl;
	cout << endl;

	cout << "Oppgave g)" << endl;
	naivePrimeNumberSearch(4);
	cout << endl;

	cout << "Oppgave h)" << endl;
	cout << findGreatestDivisor(14) << endl;
	cout << endl;


	keep_window_open();
}

