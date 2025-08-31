#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n = 371 ;
    int num = n;
    int res = 0;

    // cout << "Enter the number : ";
    // cin >> n;
    
    while(num > 0){
        int lastDigit = num % 10;
        res += pow(lastDigit , 3);
        num /= 10;
    }

    if(n == res){
        cout << "Is Armstrong";
    }else{
        cout << "Is Not Armstrong" ;
    }
    return 0;
}