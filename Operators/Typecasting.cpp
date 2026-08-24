// Operators/Typecasting.cpp
// Demonstrates implicit and explicit type conversions in C++.
//
// Implicit conversion (also called coercion) is performed automatically
// by the compiler, typically widening a value so that data loss is
// avoided.
//
// Common safe promotion order:
//     bool -> char -> short -> int -> long -> float -> double
//
// Explicit conversion is requested by the programmer.  Modern C++
// recommends C++ style casts such as static_cast over C-style casts
// because they are safer and self-documenting.

#include <iostream>

int main()
{
    std::cout << "This is an example of Implicit Conversion :\n";

    // Both operands are int, so integer division is performed.
    std::cout << 10 / 3 << std::endl;      // 3

    // 3.0 is a double, so 10 is promoted to double and
    // floating-point division is performed.
    std::cout << 10 / 3.0 << std::endl;    // 3.33333

    std::cout << "This is an example of Explicit Conversion :\n";

    // Integer division is performed first (10 / 3 == 3); the result
    // is then converted to float.
    std::cout << static_cast<float>(10 / 3) << std::endl;    // 3

    // Floating-point division is performed first (10 / 3.0 ==
    // 3.333...); the fractional part is discarded when converting to
    // int.
    std::cout << static_cast<int>(10 / 3.0) << std::endl;     // 3

    std::cout << "Yug Shah Sigma 9";

    return 0;
}