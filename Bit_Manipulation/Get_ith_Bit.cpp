#include "../myheaders.h"

void Get_ith_Bit(int num,int target){
     int mask = 1 << target;          // create bitmask
    int bit = (num & mask) != 0;     // isolate and check the bit
    cout << "The bit at position " << target << " is: " << bit << endl;
}

int main(){
    int num,target;

    cout << "Enter the number : ";
    cin >> num;
    cout << "Enter the target postion :";
    cin >> target;

    Get_ith_Bit(num,target);
}