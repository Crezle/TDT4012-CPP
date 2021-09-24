#include "mastermind.h"
#include "utilities.h"
#include "masterVisual.h"

// 4a, b, c, d, g, h, i og j)

void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    char lastChar = 'A' + (letters - 1);
    const string code = randomizeString(size,'A',lastChar);

    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    addGuess(mwin, code, size, 'A', 0);
    string guess = mwin.getInput(size,'A',lastChar);
    
    mwin.redraw();

    int correctPos = checkCharactersAndPosition(code, guess);
    int correctLet = checkCharacters(code, guess);
    int attempts = 1;

    addGuess(mwin, guess, size, 'A', attempts);
    addFeedback(mwin, correctPos, correctLet, size, attempts);
    mwin.redraw();
    attempts++;
    while ((correctPos != size) && (attempts < 6)) {
        cout << "You got " << correctPos << " letters at the right position" << endl;
        cout << "and you got " << correctLet << " of the letters right!" << endl;
        cout << endl;
        cout << "This was attempt nr: " << attempts << ". You have " << 10 - attempts << " attempts left!" << endl;
        cout << "Try again until you get all the letters right!" << endl;
        guess = mwin.getInput(size,'A',lastChar);
        addGuess(mwin, guess, size, 'A', attempts);
        addFeedback(mwin, correctPos, correctLet, size, attempts);
        mwin.redraw();
        attempts++;

        correctPos = checkCharactersAndPosition(code, guess);
        correctLet = checkCharacters(code, guess);
    }
    if (attempts <= 6) {
        cout << "Congratulations! " << code << " was the right answer!" << endl;
        cout << "You won the game in " << attempts << " attempts!" << endl;
    }
    else {
        cout << "Game over, you did not make it in 10 attempts." << endl;
    }
}

// 4e)

int checkCharactersAndPosition(string code, string guess) {
    vector<char> c(code.begin(),code.end());
    vector<char> g(guess.begin(),guess.end());
    int correctCount = 0;
    for (int i = 0; i < static_cast<int>(c.size()); i++) {
        if (c[i] == g[i]) {
            correctCount += 1;
        }
    }
    return correctCount;
}

// 4f)

int checkCharacters(string code, string guess) {
    int codeChar = 0;
    int guessChar = 0;
    int correct = 0;
    for (int i = 0; i < 6; i++) {
        codeChar = countChar(code, static_cast<char>('A' + i));
        guessChar = countChar(guess, static_cast<char>('A' + i));
        if ((codeChar > 0) && (guessChar > 0)) {   
            if (codeChar <= guessChar) {
                correct += codeChar;
            }
            else if (codeChar >= guessChar) {
                correct += guessChar;
            }
        }
    }    
    return correct;
}

// Vi bruker constexpr her ettersom vi får direkte oppgitt verdier som SKAL være konstanter fra start, constexpr
// optimaliserer også koden. "const" er nyttig hvis ikke konstanten må bli oppgitt helt fra start, f.eks. en konstant
// som kommer fra regneoperasjoner midt i programmet.