#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    const std::vector<std::vector<int>> matrix = {
        { 1,  2,  3,  4,  5 },
        { 6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
    };

    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    const int n = static_cast<int>(matrix.size());
    const int m = static_cast<int>(matrix[0].size());

    for (const auto& row : matrix) {
        if (static_cast<int>(row.size()) != m) {
            std::cerr << "Error: matrix rows have inconsistent sizes\n";
            return 1;
        }
    }

    const int layers = (std::min(n, m) + 1) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        const int top = layer;
        const int left = layer;
        const int bottom = n - layer - 1;
        const int right = m - layer - 1;

        for (int col = left; col <= right; ++col) {
            std::cout << matrix[top][col] << " ";
        }

        for (int row = top + 1; row <= bottom; ++row) {
            std::cout << matrix[row][right] << " ";
        }

        if (bottom > top) {
            for (int col = right - 1; col >= left; --col) {
                std::cout << matrix[bottom][col] << " ";
            }
        }

        if (left < right && bottom > top) {
            for (int row = bottom - 1; row > top; --row) {
                std::cout << matrix[row][left] << " ";
            }
        }
    }

    return 0;
}