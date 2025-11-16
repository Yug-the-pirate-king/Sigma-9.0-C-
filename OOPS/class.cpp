#include<iostream>
using namespace std;

class Student{ // class
    // Properties
    string name;
    float cgpa;

    public :
    
    //Methods
    void get_percentage(){
        cout << cgpa *10 << "%\n";
    }

    //Setter
    void SetName(string nameVal){
        name = nameVal;
    }
    void SetName(float cgpaval){
        cgpa = cgpaval;
    }

    //Getter
    string getName(){
        return name;
    }
    float getcgpa(){
        return cgpa;
    }
};

int main(){
    Student s1; // Object
    return 0;
}