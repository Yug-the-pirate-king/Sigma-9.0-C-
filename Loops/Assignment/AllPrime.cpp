#include <iostream>
using namespace std;

int main() {
    int n ; // input 

    bool isprime ; // is Prime

    cout << "Enter the Number : "; //input
    cin >> n;

    for(int i = 2 ; i < n ; i++){ // for number 

        isprime = true; 

        for (int j=2 ; j*j <= i; j++){ // checking prime 

            if(i%j == 0){

                isprime = false ;
                break;
            }
        }
        if(isprime){ // isprime dont change to 

                cout << i << endl;
                
            }
    }


    return 0;
}