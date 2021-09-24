#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

// VI LEGGER TIL NOEN STUDENTER FOR Å TESTE KODEN

Student Christian = {"Christian", "Kybernetikk", 22};
Student Andreas = {"Andreas", "EMIL", 21};

void createMenu() {
	int choice = -1;

	while (choice != 0) {
		cout << "Choose your desired function: " << endl;
		cout << endl;
		cout << "1: testCallByValue() " << endl;
		cout << "2: testCallByReference()" << endl;
		cout << "3: swapNumers(a, b) " << endl;
		cout << "4: isInProgram(student, study) " << endl;
		cout << "5: randomString(length) " << endl;
		cout << "6: readInputToString(lower, upper, n) " << endl;
		cout << "7: countChar(string, char) " << endl;
		cout << "8: Test grade calculator " << endl;
		cout << "9: Play Mastermind " << endl;
		cout << "0: Exit " << endl;

		cout << endl;

		cin >> choice;

		if (choice == 1) {
			testCallByValue();
			cout << endl;
		}
		else if (choice == 2) {
			testCallByReference();
			cout << endl;
		}
		else if (choice == 3) {
			int a;
			int b;
			cout << "Choose number 'a': ";
			cin >> a;
			cout << "Choose nummer 'b': ";
			cin >> b;
			swapNumbers(a, b);
			cout << "Now 'a' is equals to " << a << " and 'b' equals to " << b << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Does Christian study Kybernetikk?" << endl;
			cout << isInProgram(Christian, "Kybernetikk") << endl;
			cout << "Does Andreas study Kybernetikk?" << endl;
			cout << isInProgram(Andreas, "Kybernetikk") << endl;
			cout << endl;
		}
		else if (choice == 5) {
			int length;
			cout << "String length?: " << endl; 
			cin >> length;
			cout << "Random generated string is: " << randomizeString(length,'A','G') << endl;
			cout << endl;
		}
		else if (choice == 6) {
			readInputToString('A','F',8);
			cout << endl;
		}
		else if (choice == 7) {
			cout << countChar("Ananas", 'a') << endl;
			cout << endl;
		}
		else if (choice == 8) {
			testString();
			cout << endl;
		}
		else if (choice == 9) {
			playMastermind();
			cout << endl;
		}
		else {
			cout << "Invalid choice, try again." << endl;
			cout << endl;
		}
	}
}

int main()
{

	createMenu();

}

