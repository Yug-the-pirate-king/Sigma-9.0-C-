#include <iostream>
using namespace std;

int main() {
    int n;
    int Final_term ;
    int first_term = 0;
    int last_term = 1;

    cout << "Enter the Term : ";
    cin >> n;

    cout << first_term << endl;
    cout << last_term << endl;

    for(int i = 2; i < n; i++){
        Final_term = first_term + last_term ;
        cout << Final_term << endl;
        first_term = last_term;
        last_term = Final_term;
    }



    return 0;
}