#include <iostream>
#include <iomanip> // For setting precision

void displayMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "           # Simple Calculator #           \n";
    std::cout << "=========================================\n";
    std::cout << "Choose an operation:\n";
    std::cout << "  [+] Addition\n";
    std::cout << "  [-] Subtraction\n";
    std::cout << "  [*] Multiplication\n";
    std::cout << "  [/] Division\n";
    std::cout << "=========================================\n";
}

int main() {
    double num1, num2;
    char operation;
    bool continueCalculation = true;

    std::cout << "Welcome to the Simple Calculator!\n";

    while (continueCalculation) {
        displayMenu();

        // Input two numbers with error handling for non-numeric input
        std::cout << "\nEnter the first number: ";
        while (!(std::cin >> num1)) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(10000, '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number: ";
        }

        std::cout << "Enter the second number: ";
        while (!(std::cin >> num2)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }

        // Input the operation with a clear prompt
        std::cout << "\nSelect an operation (+, -, *, /): ";
        std::cin >> operation;

        // Perform the selected operation with formatted output
        std::cout << std::fixed << std::setprecision(2);  // Set precision for output
        switch (operation) {
            case '+':
                std::cout << "\n Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
                break;
            case '-':
                std::cout << "\n Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
                break;
            case '*':
                std::cout << "\n Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
                break;
            case '/':
                if (num2 != 0) {
                    std::cout << "\n Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
                } else {
                    std::cout << "\n Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                std::cout << "\n Error: Invalid operation selected.\n";
                break;
        }

        // Ask if the user wants another calculation
        char choice;
        std::cout << "\n Would you like to perform another calculation? (y/n): ";
        std::cin >> choice;
        continueCalculation = (choice == 'y' || choice == 'Y');
    }

    std::cout << "\n Thank you for using the calculator. Goodbye! \n";

    return 0;
}
