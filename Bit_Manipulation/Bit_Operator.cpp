#include "../myheaders.h"

int main(){
// Bitwise Operater
cout << (3&5) << "\n"; // 1  & AND
cout << (3|5) << "\n"; // 7 | OR
cout << (3^5) << "\n"; // 6 ^ XOR

//One Complement 
cout << (~6) << "\n" ; //-7  ~NOT

//Bianry Shift Operators

//left shift
cout << (7 << 2) <<"\n"; //7->00000111  after left shift -> 00011100 = 28

// note a << b -> a*(2^b)

//Right Shift
cout << (28 >> 2) << "\n"; // 7

// note a >> b -> a/(2^b)

//Practice Qs 1

//~4 -> not 4
//(4)10 = (00000100)2
//(~4)10 = (11111011)2 -> -5
cout << (~4) <<"\n";

//Practice Qs 2

//8 >> 1 -> 8/(2) = 4
cout << (8>>1) <<"\n";


return 0;
}