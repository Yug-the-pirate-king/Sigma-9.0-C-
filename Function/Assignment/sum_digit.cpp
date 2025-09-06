#include <iostream>
using namespace std;

int sum_digit(int a){
    int sum = 0;
    while(a > 0){
        sum += a%10;
        a /= 10;
    }
    return sum;
}

int main() {
    int a = 1234;
    cout << "The  sum of digit is : " << sum_digit(a);
    return 0;
}