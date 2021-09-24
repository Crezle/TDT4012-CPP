#include "read.h"


// 1a)

void writeToFile() { // Antar at filen som skrives i er bestemt
    fstream wFile;
    string write = "";
    wFile.open ("file.txt", fstream::out | fstream:: trunc);
    cout << "Write a line to 'file.txt', if you're finished, type 'quit'." << endl;
    while (wFile.is_open()) {
        cin >> write;
        if (write == "quit") {
            wFile.close();
        }
        else {
            wFile << write << endl;
        }
    }
    
}

// 1b)

void readLineNum(string textfile) { 
    // Antar at filen som skrives i er bestemt, 
    // men den som hentes fra bestemmes av bruker/programmerer på forhånd
    fstream rFile;
    string line;
    vector<string> lines;
    rFile.open(textfile, fstream::in);
    if (!rFile) {
        cout << "Error, file could not be found" << endl;
        return;
    }
    while (getline(rFile,line)) {
        lines.push_back(line);
    }
    
    rFile.close();

    fstream wFile;
    
    wFile.open("file(2).txt", fstream::out | fstream::trunc);
    for (int i = 0; i < static_cast<int>(lines.size()); i++) {
        wFile << i+1 << " " << lines[i] << endl;
    }
    wFile.close();
}

// 2a)

void sortByChar(string textfile) {
    fstream readFile;
    readFile.open(textfile, fstream::in);
    vector<int> charCount(26, 0);
    string word;
    if (!readFile) {
        cout << "Error, file could not be found" << endl;
    }
    else {
        while (readFile >> word) {
            for (int i = 0; i < static_cast<int>(word.length()); i++) {
                int charIndex = abs('a' - tolower(word[i]));
                if (charIndex >= 0 && charIndex < 26) {
                    charCount[charIndex]++;
                }
            }
        }
    }
    cout << "Statistikk fra " << textfile << " for tegn a-z." << endl << endl;
    for (int j = 0; j < static_cast<int>(charCount.size()); j++) {
        if ((j % 3) == 0 && j != 0) {
            cout << endl;
        }
        cout << static_cast<char>('a' + j) << ": " << setw(4) << charCount[j] << "  ";
    }
    cout << endl;
    readFile.close();
}