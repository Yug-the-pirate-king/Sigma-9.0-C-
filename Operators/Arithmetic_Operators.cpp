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

cout << "++ : " << --a << endl; // 5 but a = 6

cout << "-- : " << ++b << endl; // 10 but b = 9

cout << " a += b : " << a + b << endl; // 15

cout << "a -= b : " << a - b  << endl; // 5

cout << " a *= b : " << a * b << endl; // 50

cout << "a /= b : " << a / (float)b << endl; // 0.5

cout << endl ;

cout << "Relational Operators 0 false 1 True"<< endl;

cout << " a > b : " << (a > b) << endl; // 0

cout << "a < b : " << (a < b) << endl; // 1

cout << " a == b : " << (a == b) << endl; // 0

cout << "a /= b : " << (a != b) << endl; // 1

return 0 ;
}