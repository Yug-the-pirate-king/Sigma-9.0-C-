/**
 * @file Calculator.cpp
 * @brief Simple calculator functions demonstrating addition and subtraction.
 *
 * This file contains two utility functions, `sum` and `diff`, and a `main`
 * entry point that demonstrates their usage with two integer operands.
 */

#include <iostream>

/**
 * @brief Computes the sum of two integers.
 *
 * @param a The first integer operand.
 * @param b The second integer operand.
 * @return The arithmetic sum of `a` and `b`.
 * @note This function uses built-in `int` arithmetic, so overflow is possible
 *       if the result exceeds the range of `int`.
 */
int sum(int a, int b) {
    return a + b;
}

/**
 * @brief Computes the difference between two integers.
 *
 * @param a The minuend (the number to subtract from).
 * @param b The subtrahend (the number to subtract).
 * @return The arithmetic difference `a - b`.
 * @note This function uses built-in `int` arithmetic, so overflow is possible
 *       if the result exceeds the range of `int`.
 */
int diff(int a, int b) {
    return a - b;
}

/**
 * @brief Program entry point.
 *
 * Demonstrates the `sum` and `diff` functions using sample operands.
 *
 * @return 0 on successful execution.
 */
int main() {
    // Sample operands used for the demonstration.
    int a = 5;
    int b = 10;

    // Display the sum of a and b. Expected result: 15.
    std::cout << "The Sum is " << sum(a, b) << std::endl;

    // Display the difference of a and b. Expected result: -5.
    std::cout << "The Diff is " << diff(a, b);

    return 0;
}