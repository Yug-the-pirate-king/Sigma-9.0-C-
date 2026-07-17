#include <iostream>
using namespace std;

int main() {
    // Initialize two integer operands
    int a = 5;
    int b = 10;

    // Display the initial values on separate lines for clarity
    cout << "a = " << a << endl; // 5
    cout << "b = " << b << endl; // 10

    cout << "Binary Arithmetic Operators" << endl;

    cout << "Addition       : " << a + b << endl; // 15
    cout << "Subtraction    : " << a - b << endl; // -5
    cout << "Multiplication : " << a * b << endl; // 50
    cout << "Division       : " << a / b << endl; // 0 (integer division truncates)

    // Modulus is only well-defined for non-zero divisor; b is 10 here
    cout << "Modulus        : " << b % a << endl; // 0

    cout << "Unary Arithmetic Operators" << endl;

    // Post-increment: use current value, then increment
    cout << "a++ : " << a++ << endl; // prints 5, then a becomes 6

    // Post-decrement: use current value, then decrement
    cout << "b-- : " << b-- << endl; // prints 10, then b becomes 9

    // Pre-decrement: decrement first, then use value
    cout << "--a : " << --a << endl; // a becomes 5, prints 5

    // Pre-increment: increment first, then use value
    cout << "++b : " << ++b << endl; // b becomes 10, prints 10

    // The following expressions demonstrate results; variables are not modified
    cout << "a + b : " << a + b << endl; // 15
    cout << "a - b : " << a - b << endl; // -5
    cout << "a * b : " << a * b << endl; // 50

    // Cast to double to perform floating-point division
    cout << "a / b : " << a / static_cast<double>(b) << endl; // 0.5

    cout << endl;

    cout << "Relational Operators (0 = false, 1 = true)" << endl;

    cout << "a > b  : " << (a > b)  << endl; // 0
    cout << "a < b  : " << (a < b)  << endl; // 1
    cout << "a == b : " << (a == b) << endl; // 0
    cout << "a != b : " << (a != b) << endl; // 1

    return 0;
}