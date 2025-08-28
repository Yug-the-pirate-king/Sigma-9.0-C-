#include <iostream>
#define pencil 30 // this is call a macros they do not take storage in code .
#define pen 50
#define eraser 10
using namespace std;

int main() { 
float num_pencil, num_pen, num_eraser , Total;

cout << "Enter The Number of Pencil: ";
cin >> num_pencil;

cout << "Enter The Number of Pen: ";
cin >> num_pen;

cout << "Enter The Number of Eraser: ";
cin >> num_eraser;

Total = num_pencil*pencil + num_pen*pen + num_eraser*eraser ;

Total *= 1.18;

cout << "The Total bill is : " << Total ;

return 0 ;
}