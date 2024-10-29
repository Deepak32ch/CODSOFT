#include <iostream>
#include <random>  // For random number generation

int main() {
    // For setting a random number generator
    std::random_device rd;   // it will help to find a random number from the hardware
    std::mt19937 gen(rd());  // Seed the generator
    std::uniform_int_distribution<> distr(1, 100); // Define the range

    int randomNumber = distr(gen); // Generate the random number between 1 to 100
    int userGuess = 0;
    int attempts = 0;

    std::cout << "* Welcome to the Number Guessing Game! *\n";
    std::cout << "I've picked a random number between 1 and 100.\n";
    std::cout << "Your task is to guess it correctly!\n";
    std::cout << "Let's get started!\n\n";

    // Loop until the user guesses correctly
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;  // for counting each guess attempt

        if (userGuess > randomNumber) {
            std::cout << " Oops! That's too high. Try a lower number.\n\n";
        } else if (userGuess < randomNumber) {
            std::cout << " Too low! Aim a bit higher.\n\n";
        } else {
            std::cout << "** Congratulations! **\n";
            std::cout << "You've guessed the correct number: " << randomNumber << "\n";
            std::cout << "It took you " << attempts << " attempts.\n";
        }
    }

    std::cout << "\nThanks for playing! Hope you enjoyed the game. \n";
    std::cout << "Goodbye!\n";

    return 0;
}
