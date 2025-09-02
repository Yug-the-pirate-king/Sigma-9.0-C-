#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        bool val = (i % 2 == 0);  // even row -> start with 1, odd row -> start with 0
        
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = !val;  // toggle
        }
        cout << endl;
    }

    return 0;
}
