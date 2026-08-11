#include <cstdint>
#include <iostream>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::int64_t n = 0;
    std::cout << "Enter the Term : ";
    if (!(std::cin >> n) || n < 0) {
        return 1;
    }

    std::uint64_t first_term = 0;
    std::uint64_t last_term = 1;

    if (n > 0) {
        std::cout << first_term << '\n';
    }
    if (n > 1) {
        std::cout << last_term << '\n';
    }

    for (std::int64_t i = 2; i < n; ++i) {
        if (last_term > std::numeric_limits<std::uint64_t>::max() - first_term) {
            return 1;
        }
        std::uint64_t final_term = first_term + last_term;
        std::cout << final_term << '\n';
        first_term = last_term;
        last_term = final_term;
    }

    return 0;
}