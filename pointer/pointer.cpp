#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int *ptr = &n;

    cout << &n << " = " << ptr << "\n"; // pointer takes 8 btyes.
    
    return 0;
}