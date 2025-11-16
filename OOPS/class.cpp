#include<iostream>
using namespace std;

class Student{ // class
    // Properties
    string name;
    float cgpa;

    //Methods
    void get_percentage(){
        cout << cgpa *10 << "%\n";
    }

};

int main(){
    Student s1; // Object
    return 0;
}