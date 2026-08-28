#include <iostream>
#include <vector>

int main() {
    int numRows = 0;
    int numCols = 0;

    std::cout << "Enter two size of array: ";
    std::cin >> numRows >> numCols;

    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols));

    std::cout << "Enter array elements: ";
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    std::cout << "Array elements are: " << '\n';
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}