#include <iostream>
using namespace std;

int factorial(int a){
 return a > 1?a * factorial(a-1):a;

} 

int main() {
    int a = 5;

    cout << "The Factorial of the number is : " << factorial(a);
    return 0;
}