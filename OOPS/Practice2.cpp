#include <iostream>
using namespace std;

class A {
    public:
    A(){
        cout <<"Constructor A. \n";
    }
    ~A(){
        cout <<"Destructor A. \n";
    }
};

class B:public A{
    public:
     B(){
        cout <<"Constructor B. \n";
    }
    ~B(){
        cout <<"Destructor B. \n";
    }
};

int main() {
    B obj;
    /*output
    Constructor A.
    Constructor B.
    Destructor B.
    Destructor A.
    */

    return 0;
}