#include <iostream>
#include <limits>
#include <string>

/**
 * Prompts the user and reads a positive integer from standard input.
 *
 * If the input is not a valid integer or is not greater than zero,
 * the function returns false and leaves outValue unchanged.
 *
 * @param prompt   The message displayed to the user.
 * @param outValue Reference to store the validated integer.
 * @return true    If a positive integer was successfully read.
 * @return false   If the input was invalid or non-positive.
 */
bool readPositiveInteger(const std::string& prompt, int& outValue) {
    std::cout << prompt;

    int value = 0;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    // Discard any remaining characters on the current input line.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (value <= 0) {
        return false;
    }

    outValue = value;
    return true;
}

/**
 * Prints the integers from 1 to count (inclusive), each on a separate line.
 *
 * @param count The upper bound of the number range to print.
 */
void printNumbersFromOneTo(int count) {
    for (int number = 1; number <= count; ++number) {
        std::cout << number << '\n';
    }
}

int main() {
    int inputNumber = 0;

    if (!readPositiveInteger("Enter the Number : ", inputNumber)) {
        std::cerr << "Error: Please enter a valid positive integer.\n";
        return 1;
    }

    printNumbersFromOneTo(inputNumber);

    return 0;
}