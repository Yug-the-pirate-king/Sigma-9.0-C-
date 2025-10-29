#include "../myheaders.h"

void upadateithbit(int num ,int ith,int val){
    num = num & ~(1 << ith); 

    num = num | (val << ith);

    cout << num;
}

int main(){
    int num , ith,val;
    cout <<"Enter the number : \n";
    cin >> num;
    cout <<"Enter the postion : \n";
    cin >> ith;
    cout << "Enter the val : \n";
    cin >> val;

    upadateithbit(num ,ith,val);
}