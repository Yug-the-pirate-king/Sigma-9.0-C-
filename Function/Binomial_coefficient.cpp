#include <iostream>
#include <stdexcept>
#include <limits>

unsigned long long binomial_coefficient(int n, int r) {
    if (n < 0 || r < 0) {
        throw std::invalid_argument("n and r must be non-negative");
    }
    if (r > n) {
        throw std::invalid_argument("r must not exceed n");
    }
    if (r == 0 || r == n) {
        return 1ULL;
    }
    if (r > n - r) {
        r = n - r;
    }
    unsigned long long result = 1ULL;
    for (int i = 1; i <= r; ++i) {
        unsigned long long term = static_cast<unsigned long long>(n - r + i);
        if (result > std::numeric_limits<unsigned long long>::max() / term) {
            throw std::overflow_error("binomial coefficient result is too large");
        }
        result *= term;
        result /= static_cast<unsigned long long>(i);
    }
    return result;
}

int main() {
    int n = 4, r = 2;
    try {
        std::cout << "The Binmial Coefficient : " << binomial_coefficient(n, r);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}