#pragma once
#include "LinkedList.h"

void MainMenu();
int getValidChoice(const string& prompt = "\nEnter your choice: ", int min = 1, int max = 7);
int getValidInput(const string& prompt);

void MainMenu() {
    cout << "\n------------- Main Menu ----------\n";
    cout << "1. Insert a Polynomial\n";
    cout << "2. Add Two Polynomials\n";
    cout << "3. Subtract Two Polynomials\n";
    cout << "4. Multiply Two Polynomials\n";
    cout << "5. Evaluate a Polynomial\n";
    cout << "6. Display all Polynomials\n";
    cout << "7. Exit\n";
}

int getValidChoice(const string& prompt, int min, int max) {
    int choice;
    string input;
    bool isValid = false;

    while (!isValid) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> choice && !(ss >> input) && choice >= min && choice <= max) {
            isValid = true;
        } else {
            cout << "\nInvalid choice! Please enter a number between " << min << " and " << max << ".\n";
        }
    }
    return choice;
}

int getValidInput(const string& prompt) {
    int x;
    string input;
    bool isValidNumber = false;

    do {
        cout << prompt;
        getline(cin, input);
        isValidNumber = true;

        if (input.empty() || (input[0] == '-' && input.size() == 1)) {
            isValidNumber = false;
        } else {
            for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) {
                if (!isdigit(input[i])) {
                    isValidNumber = false;
                    break;
                }
            }
        }

        if (isValidNumber) {
            stringstream(input) >> x;
        } else {
            cout << "\nInvalid Input! Please enter a valid integer.\n";
        }
    } while (!isValidNumber);

    return x;
}
