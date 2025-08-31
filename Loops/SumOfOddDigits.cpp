#include <iostream>
using namespace std;

int main() {
    int n ;
    int sum = 0;

    cout << "Enter the number : ";
    cin >> n;
    while(n>0){
        if(n%2 != 0){

        sum += n%10;
        
    }
        n /= 10;
    }

    cout << sum ;
    return 0;
}