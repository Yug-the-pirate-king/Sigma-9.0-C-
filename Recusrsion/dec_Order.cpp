#include <iostream>
using namespace std;

void dec_order(int n){
cout << n << "\n";
if(n == 0){
    return ;
}
else{
    dec_order(n-1);
}
}

int main() {

    dec_order(5);
    
    return 0;
}