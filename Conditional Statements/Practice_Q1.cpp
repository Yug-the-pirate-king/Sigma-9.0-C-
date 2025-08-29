//To find the Greatest of two numbers using if else
#include<iostream>
using namespace std;

int main(){
    int num1,num2;

    cout << "Enter the 1st Number : ";
    cin >> num1 ;

    cout << "Enter the 2nd Number : ";
    cin >> num2 ;

    if(num1 == num2){
        cout << "Both the numbers are same."; // i know there are a million other way the best is max(num1,num2)
        return 1;
    }
    if(num1 > num2){
        cout << num1 <<" Number is Bigger then "<< num2;
    }
    else{
        cout << num2 <<" Number is Bigger then "<< num1;
    }
    return 0;
}