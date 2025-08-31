#include <iostream>
using namespace std;

int main() {
    int n ;
    int lastDigit ;
    int res = 0;

    cout << "Enter the number : ";
    cin >> n;
    while(n>0){
        lastDigit = n%10;
        res = res * 10 + lastDigit;
        n /= 10;
    }

    cout << res ;
    return 0;
}