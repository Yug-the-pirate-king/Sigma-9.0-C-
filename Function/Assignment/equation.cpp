#include <iostream>
#include <math.h>
using namespace std;

int equation (int a , int b){
    return pow(a,2) + pow(b,2) + 2*a*b;
}

int main() {
    int a = 10 ,b = 20 ;

    cout << "The output is : " << equation(a,b);
    
    return 0;
}