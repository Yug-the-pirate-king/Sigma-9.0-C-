#include <iostream>
using namespace std;

class Parent{
    public:
    void show(){
        cout << "This is Parent class.";
    }
    virtual void hello(){
        cout  <<"Hello from Parent.";
    }
};

class Child : public Parent{
    public : 
    void show(){
        cout << "This is Child Class.";
    }
    void hello(){
        cout << "Hello from Child";
    }
};

int main() {
    Child c1;
    c1.show(); // function overriding
    Parent *ptr;
    ptr = &c1;
    return 0;
}