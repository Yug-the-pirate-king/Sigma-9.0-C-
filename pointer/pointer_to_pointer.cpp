#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int *ptr = &n;
    int **ptr2 = &ptr;

    cout << "Address of n is : " << ptr << "\n";
    cout << "Address of ptr is : " << ptr2 << "\n";
    
    return 0;
}