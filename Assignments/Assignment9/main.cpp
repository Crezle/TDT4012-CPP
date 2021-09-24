#include "functions.h"
#include "matrix.h"
#include "intermezzo.h"

int main()

{
	// Oppgave 1
	createFibonacci();

	// Oppgave 2
	Matrix m(5,3);
	cout << m;
	cout << endl;
	Matrix n(m);
	cout << n;

	// Oppgave 3
	dummyTest();

	// Oppgave 5

	Matrix A(2,2);
	A.set(0,0,1.0);
	A.set(0,1,2.0);
	A.set(1,0,3.0);
	A.set(1,1,4.0);
	cout << A;

	cout << endl;

	Matrix B(2,2);
	B.set(0,0,4.0);
	B.set(0,1,3.0);
	B.set(1,0,2.0);
	B.set(1,1,1.0);
	cout << B;

	cout << endl;

	Matrix C(2,2);
	C.set(0,0,1.0);
	C.set(0,1,3.0);
	C.set(1,0,1.5);
	C.set(1,1,2.0);
	cout << C;

	cout << endl;

	A = -A;
	cout << A << '\n' << B << '\n' << C << '\n';

	int x;
	cin >> x;
}