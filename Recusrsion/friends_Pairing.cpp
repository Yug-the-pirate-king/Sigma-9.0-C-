#include"../myheaders.h"

//Find total ways in which n friends can be paired up. Each friend can only be paired once.

int friends_Pairing(int n){
    if(n == 1){
        return 1;
    }

    if(n == 2){
        return 2;
    }

    return friends_Pairing(n-1) + (n-1)*friends_Pairing(n-2);
}

int main(){
    int n = 3;
    cout << "The total number of ways in which friends can be paired up :" << friends_Pairing(n);

    return 0;
}