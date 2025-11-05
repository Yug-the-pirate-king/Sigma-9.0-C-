#include "../myheaders.h"

void Count_set_Bit(int num){
    int count = 0;

    while(num >0){
        int lastbit = num & 1;
        count += lastbit;
        num = num >> 1;
    }

    cout << "The total number of bits is " << count;
}

int main(){
 int num ;
    cout <<"Enter the number : \n";
    cin >> num;

    Count_set_Bit(num);

}