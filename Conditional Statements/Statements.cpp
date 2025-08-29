#include<iostream>
using namespace std ;

int main(){
    int age ;

    cout << "Enter the Age\n";
    cin >> age ; // input age 

    if(age >= 18){ // Check is age is greater(>) or equal to(=) 18;

cout << "Can Vote";// output 1

    }
    else{

        cout << "Can't vote" ; // output 2
        
    }
    return 0;
}