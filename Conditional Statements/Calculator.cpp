#include <iostream>
using namespace std;

int main() {
    float a , b;
    char sign;

    cout << "Enter the 1st number : ";
    cin >> a ;
    cout << "Enter the 2nd number : ";
    cin >> b;
    cout << "Enter the Operations";
    cin >> sign;

    // Calculator 

    if(sign == '+'){
        cout << a+b ;
    }
    else if(sign == '-'){
        cout << a-b;
    }
    else if(sign == '*'){
        cout << a*b;
    }
    else if(sign == '/'){
        cout << a/b;
    }
    else{
        cout << "Invalid";
    }
    return 0;
}