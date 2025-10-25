#include "../myheaders.h"

void Odd_or_Even(int Num){
    bool is_odd = false;

    //Bit Marks -> are used to access specific bits in a byte of data.

    if(Num & 1){ // & id Bit masks
        is_odd = true;
    }

    if(is_odd){
        cout << Num << " is Odd\n";
    }
    else{
        cout << Num << " is Even\n";
    }
    
}

int main(){
    int Num = 2;

    Odd_or_Even(Num);
}