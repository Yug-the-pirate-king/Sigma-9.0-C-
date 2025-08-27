#include <iostream>
using namespace std;

int main() { 
int P, T, R;

cout << "Enter Principal : ";
cin >> P;

cout << "Enter Rate : ";
cin >> R;

cout << "Enter Time  : ";
cin >> T;

cout << "The Simple Interest is : " << P*T*R/100 ;

return 0 ;
}