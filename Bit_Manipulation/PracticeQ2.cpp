#include "../myheaders.h"

void WAF(int num ,int i){
    int mark = ~(0);
    mark = mark << i;
    cout << (num & mark);
}

int main(){
    int num,i;
    cout <<"Enter the number : \n";
    cin >> num;
    cout <<"Enter the postion : \n";
    cin >> i;

    WAF(num,i);
}