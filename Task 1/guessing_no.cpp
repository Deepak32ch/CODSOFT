/*This program is for generating a random number and guessing this number 
by user*/

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    // Initialize random seed based on the current time
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;

    cout << "I have generated a random number between 1 and 100.\n";
    cout << "Can you guess it?\n";

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number.\n";
        }
    }

    return 0;
}

