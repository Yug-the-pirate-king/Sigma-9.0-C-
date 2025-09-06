#include <iostream>
using namespace std;

void Decimal_to_Binary(int n){
    int dub = n;
    int final = 0;
    int pow = 1;
    while(dub > 0){
        int LastDigit = dub %2;
        final += LastDigit * pow;
        pow *= 10;
        dub /= 2;
    }

    cout << final << endl;
}

int main() {
    Decimal_to_Binary(25); //11001

    Decimal_to_Binary(49); //110001

    Decimal_to_Binary(31); //11111

    Decimal_to_Binary(88); //1011000
    return 0;
}