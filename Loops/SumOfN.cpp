#include <iostream>
using namespace std;

int main() {
    int Input ;
    int sum = 0;

    cout << "Enter the Number : ";
    cin >> Input;

    for(int i = 1; i <= Input; i++){

        sum += i;
        
    }

    cout << sum ;
    return 0;
}