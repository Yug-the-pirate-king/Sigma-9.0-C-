#include <iostream>
using namespace std;

void palindrome(int a) {
    int original = a;
    int reversed = 0;

    while (a > 0) {
        int digit = a % 10;         // get last digit
        reversed = reversed * 10 + digit; // build reversed number
        a /= 10;                    // remove last digit
    }

    if (reversed == original) {
        cout << "The number is palindrome";
    } else {
        cout << "The number is not palindrome";
    }
}

int main() {
    int a = 123;
    palindrome(a);
    return 0;
}
