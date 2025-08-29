//To find the Greatest of two numbers using if else
#include<iostream>
using namespace std;

int main(){
    int num1;

    cout << "Enter the 1st Number : ";
    cin >> num1 ;

    if(num1%2 == 0){
        cout << num1 <<" Is a even Number.";
    }
    else{
        cout << num1 <<" Is a odd Number."<< num1;
    }
    return 0;
}