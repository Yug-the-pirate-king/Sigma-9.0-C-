// Polymorphism:
//polymorphism is the ability of object to take on different forms or behave in different ways denpending on the context in which they are used.

// there are two type of polymorphism 

//Compile time polymorphism 

//run time polymorphism
#include <iostream>
#include<string>
using namespace std;

class Print{
    public:
    void show(int x){
        cout<< "int :" << x<<"\n";
    }

    void show(string x){
        cout <<"Stirng :" << x <<"\n";
    }
};

int main() {
    Print p;
    p.show(24);
    p.show("yug");
    return 0;
}