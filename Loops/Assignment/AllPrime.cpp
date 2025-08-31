#include <iostream>
using namespace std;

int main() {
    int n;
    int isprime ;
    cout << "Enter the Number : ";
    cin >> n;

    for(int i = 2 ; i < n ; i++){
        isprime = true;
        for (int j=2 ; j*j <= i; j++){
            if(i%j == 0){
                isprime = false ;
                break;
            }
        }
        if(isprime){
                cout << i << endl;
            }
    }


    return 0;
}