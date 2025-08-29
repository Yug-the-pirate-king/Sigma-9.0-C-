#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter the Number";
    cin >> number;

    int ognumber = number;
    int u = number%10;
    number /= 10;
    int d = number%10;
    number /= 10;
    int h = number%10;

    if((u*u*u)+(h*h*h)+(d*d*d) == ognumber){
        cout << ognumber <<" is armstorng number";
    }else{
cout << ognumber <<" is not armstorng number";
    }
    return 0;
}