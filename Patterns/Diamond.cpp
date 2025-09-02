#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // Top half
    for(int i = 0; i < n; i++) {
        // spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // stars
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Bottom half
    for(int i = n - 2; i >= 0; i--) {
        // spaces
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // stars
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
