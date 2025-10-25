#include "../myheaders.h"

void Odd_or_Even(int Num){
    bool is_odd = false;

    if(Num & 1){
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