//
//  main.cpp
//  mg6392_hw5_q2
//
//  Created by Max Grove on 8/11/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int STARTING_GUESSES = 5;

int main() {
    int hiddenNumber, input, guessesLeft = STARTING_GUESSES;
    int topRange = 100, bottomRange = 1;
    bool correctGuess = false;
    
    srand(time(0)); // set seed for random number generator
    
    hiddenNumber = (rand() % 100) + 1; //random number between 1 and 100
    
    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    
    while (guessesLeft > 0 && !correctGuess) {
        cout << "Range: [" << bottomRange << ", " << topRange << "], ";
        cout << "Number of guesses left: " << guessesLeft << endl;
        cout << "Your guess: ";
        cin >> input;
        guessesLeft--;
        
        if (input == hiddenNumber) {
            correctGuess = true;
            cout << "Congrats! You guessed my number in ";
            cout << STARTING_GUESSES - guessesLeft;
            cout << " guesses." << endl;
        }
        else {
            if (guessesLeft == 0 && !correctGuess) {
                cout << "Out of Guesses! My number is " << hiddenNumber << endl;
            }
            else if (hiddenNumber > input) {
                cout << "Wrong! My number is bigger." << endl << endl;
                bottomRange = input + 1;
            }
            else {
                cout << "Wrong! My number is smaller." << endl << endl;
                topRange = input - 1;
            }
        }
    }
    
    return 0;
}
