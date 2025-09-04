#include <iostream>
using namespace std;

void isEven(int a){
if(a%2 == 0){
    cout << "Is Even";
}else{
    cout << "Is Odd";
}
}

int main() {
    int i = 5;

    isEven(i);

    return 0;
}