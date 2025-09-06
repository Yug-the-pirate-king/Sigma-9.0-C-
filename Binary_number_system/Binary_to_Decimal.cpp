#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int b = 0001;
    int db = b;
    int dec = 0;
    int pow = 1;
// while (db > 0)
// {
//     db /= 10;
//     count++;
// }


//     for(int i = 0; i<count+1;i++){
//         int bit = b%10;
//         dec += bit*pow(2,i);
//         b /= 10;
//     }

while(db > 0){
    int lastDigit = db % 10;
    dec += lastDigit * pow;
    pow *= 2;
    db /= 10;
}

// 63
// 22
// 21
// 50

    cout <<"The Number is : " << dec;
    return 0;
}