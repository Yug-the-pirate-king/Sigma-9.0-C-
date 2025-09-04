#include <iostream>
using namespace std;

bool isPrime(int a){
    bool p = true;
    for(int i = 2 ; i*i <= a; i++){
        if(a%i == 0){
            p = false;
            break;
        }
    }
    return p;
}

void print_prime(int n){
    for(int i = 2 ; i < n;i++){
        if(isPrime(i)){
            cout << i << " ";
        }
    }

}

int main() {
    int i = 100;

    print_prime(i);
    
    return 0;
}