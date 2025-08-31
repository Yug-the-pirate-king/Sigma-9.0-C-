#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n ;
    int res = 0;

    cout << "Enter the number : ";
    cin >> n;
    int i = n;
    
    while(n > 0){
        res += pow((n%10) , 3);
        n /= 10;
    }

    if(res == i){
        cout << "Is Armstrong";
    }else{
        cout << "Is Not Armstrong" ;
    }
    return 0;
}