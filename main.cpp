#include <iostream>
#include <string>
#include <vector>
#include "lab1/gcd.h"
#include "lab2/lcm.h"
#include "lab2/missing_number.h"

void calculateGCD() {
    int num1, num2;
    std::string input;

    std::cout << "Enter two integers separated by space to calculate GCD (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    if (sscanf(input.c_str(), "%d %d", &num1, &num2) != 2) {
        std::cout << "Please enter valid integers.\n";
        return;
    }

    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << "\n";
}

void calculateLCM() {
    int num1, num2;
    std::string input;

    std::cout << "Enter two integers separated by space to calculate LCM (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    if (sscanf(input.c_str(), "%d %d", &num1, &num2) != 2) {
        std::cout << "Please enter valid integers.\n";
        return;
    }

    std::cout << "The LCM of " << num1 << " and " << num2 << " is: " << lcm(num1, num2) << "\n";
}

void findMissingNumberOption() {
    int n;
    std::string input;

    std::cout << "Enter the value of n to generate an array (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    try {
        n = std::stoi(input);
    } catch (...) {
        std::cout << "Please enter a valid integer for n.\n";
        return;
    }

    std::vector<int> numbers = generateArray(n);

    std::cout << "Generated array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int missing_number = findMissingNumber(numbers, n);

    std::cout << "The missing number is: " << missing_number << std::endl;
}

int main() {
    std::string choice;
    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Calculate GCD\n";
        std::cout << "2. Calculate LCM\n";
        std::cout << "3. Find Missing Number\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            calculateGCD();
        } else if (choice == "2") {
            calculateLCM();
        } else if (choice == "3") {
            findMissingNumberOption();
        } else if (choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}