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
    void show(int x){ // function overloading
        cout<< "int :" << x<<"\n";
    }

    void show(string x){// function overloading
        cout <<"Stirng :" << x <<"\n";
    }
};

class Complex{
    private:
    int real;
    int img;
    public:
    Complex(int real,int img){
        this->real= real;
        this->img = img;
    }

    void print(){
        cout << this->real << " + " <<this->img<<"i\n";
    }

    Complex operator + (const Complex &obj){
        return Complex(real + obj.real, img + obj.img);
    }

    Complex operator - (const Complex &obj){
        return Complex(real - obj.real, img - obj.img);
    }
};

int main() {
    Print p;
    p.show(24);
    p.show("yug");

    Complex c1(1,2);
    Complex c2(3,4);
    c1.print();
    c2.print();

    Complex c3 = c1 + c2;
    c3.print();

    Complex c4 = c2 - c1;
    c4.print();
    return 0;
}