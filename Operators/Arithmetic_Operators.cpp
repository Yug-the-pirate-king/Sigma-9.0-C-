#include <iostream>
using namespace std;

int main() {

int a = 5;
int b = 10;

cout << a ; // 5
cout << b ; // 10
cout << "Binary Arithmetic Operators" << endl;

cout << "Addition : " << a + b << endl; // 15

cout << "Subtracition : " << a - b << endl; // -5

cout << "Multiplication : " << a * b << endl; // 50

cout << "Division : " << a / b << endl; // 0 Implicit Conversion ykyk

cout << "Modules : " << b % a << endl; // 0

cout << "Unary Arithmetic Operators"<< endl;

cout << "++ : " << a++ << endl; // 5 but a = 6

cout << "-- : " << b-- << endl; // 10 but b = 9


return 0 ;
}