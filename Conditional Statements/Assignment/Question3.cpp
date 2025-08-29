#include <iostream>
using namespace std;

int main() {
    int a = 63 , b = 36;
    bool x =(a < b)?true : false;
    int y = (a > b)?a:b;
    cout << x << " , " << y << endl;
    return 0;
}