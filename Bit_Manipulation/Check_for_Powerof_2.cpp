#include "../myheaders.h"

void powerChecker(int n) {
    if((n&(n-1))== 0){
        cout << "Power of 2";
    }
    else{
        cout << "Not Power of 2";
    }
}


int main(){
    int n;
    cout << "Enter the number :\n";
    cin >> n;

    powerChecker(n);
}