#include "../myheaders.h"

void Exponentiation(int b,int e){
    int ans = 1;

    while(e >0){
        int lastbit = e & 1;
        if(lastbit){
            ans = ans * b;
        }

        b *= b;

        e = e >> 1;
    }

    cout << ans;
}

int main(){
 int base,exponent;
    cout <<"Enter the Base : \n";
    cin >> base;
    cout << "Enter the Exponent :\n";
    cin >> exponent;


    Exponentiation(base ,exponent);

}