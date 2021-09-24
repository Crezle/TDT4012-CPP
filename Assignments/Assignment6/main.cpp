#include "read.h"
#include "Course.h"
#include "temps.h"

void menu() {
	cout << "Which excersise do you want to check?: \n\n";
	int ans = -1;
	cout << "1: Lese fra og skrive til fil \n";
	cout << "2: Lese fra fil: tegnstatistikk \n";
	cout << "3: Map: Emnekatalog \n";
	cout << "4: Lesing fra en strukturert fil \n";
	cout << "5: Plotting av graf (WIP) \n";
	cout << "0: Avslutt \n\n";

	while (ans != 0) {
		cin >> ans;
		if (ans == 1) {
			writeToFile();
			readLineNum("file.txt");
		}
		if (ans == 2) {
			sortByChar("grunnlov.txt");
		}
		if (ans == 3) {
			courses();
 		}
		if (ans == 4) {
			tempStats(readTemps("temperatures.txt"));
		}
	}
}

int main() {
	menu();	
}

