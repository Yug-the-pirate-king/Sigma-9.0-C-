#include <iostream>
using namespace std;

int main() {
    double income, tax = 0;

    cout << "Please Enter your income in Lakhs: ";
    cin >> income;

    if (income <= 5) {
        tax = 0;
    }
    else if (income <= 10) {
        tax = (income - 5) * 0.2;  // only the part above 5 taxed at 20%
    }
    else {
        tax = (5 * 0.2) + (income - 10) * 0.3; // 5L @20% + rest @30%
    }

    cout << "Tax you have to pay is " << tax << " Lakhs" << endl;
    return 0;
}
