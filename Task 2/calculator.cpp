/*This code is for a calculator that perform a basic arithmethic operations*/

#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double num1, num2, result;
    char operation;

    // Ask the user to input two numbers
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Ask the user to choose an operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    // Perform the calculation based on the operation entered
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;

        case '/':
            // Check if the second number is zero to avoid division by zero
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Error! Invalid operation." << endl;
    }

    return 0;
}

