#include <iostream>
using namespace std;

int larg(int a,int b,int c){
    return a > b ?((a > c) ? a : c) : ((b > c)? b : c);
}

int main() {
    int a = 1,b = 2,c =3;

    cout << "The larg of 3 num is : " << larg(a , b, c);
    return 0;
}