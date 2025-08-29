#include <iostream>
using namespace std;

int main() {
    int a = 5;
    
    if(++a*5 <= 25){
        cout << "Hello\n";
    }
    else{
        cout << "Bye\n";
    }
    return 0;
}