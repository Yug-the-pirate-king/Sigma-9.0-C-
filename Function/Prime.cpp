#include <iostream>
using namespace std;

void isPrime(int a){
    bool p = true;
    for(int i = 2 ; i*i <= a; i++){
        if(a%i == 0){
            p = false;
            break;
        }
    }
    if(p){
        cout << "Is prime";
    }else{
        cout << "Not Prime";
    }
}

int main() {
    int i = 4;

    isPrime(i);
    
    return 0;
}