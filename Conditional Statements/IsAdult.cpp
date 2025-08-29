#include<iostream>
using namespace std;

int main(){
    bool isAdult ;
    int age ;

    cout << "Enter the age : ";
    cin >> age;

    isAdult = age >= 18 ? true : false;

    cout << isAdult;
}
