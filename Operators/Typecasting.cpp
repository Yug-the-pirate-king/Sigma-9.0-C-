#include <iostream>
using namespace std;

/* Typecasting 
convertion of Data from one type to another.

There are two type of Typecasting. 

Implicit Conversion 
Done by compiler to avoid data loss

bool -> char -> int -> float -> doubt

Explicit Conversion
forced By the programmer

*/
int main() {
    cout << "This is an example of Implicit Conversion :\n" ;
    cout << 10/3 << endl ; // 3
    cout << 10/3.0 << endl ; // 3.33

    cout << "This is an example of Explicit Conversion :\n" ;
    cout << (float)(10/3) << endl ; // 3 because float of 3 is 3
    cout << (int)(10/3.0) << endl ; // 3

    cout << "Yug Shah Sigma 9" ; 
return 0 ;
}