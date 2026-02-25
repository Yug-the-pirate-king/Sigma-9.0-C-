#include <iostream>
using namespace std;

class Complex{
    public:
    int a,b;
    Complex(int a,int b){
        this->a = a;
        this->b = b;
    }

    void print(){
        if(this->b < 0){
            cout<< a << " - " <<b*(-1)<<"i\n";
        }
        else{
            cout<< a << " + " <<b<<"i\n";
        }
    }
    Complex operator-(Complex &obj2){
        // 'this->a' is the first object, 'obj2.a' is the second object
        int R = this->a - obj2.a;
        int I = this->b - obj2.b;
        
        // Return a new Complex object with the subtracted values
        return Complex(R, I); 
    }
};

void add(Complex &obj1, Complex &obj2){
    int R = obj1.a+obj2.a;
    int I =obj1.b + obj2.b;
     if(I < 0){
            cout<< R << " - " <<I*(-1)<<"i\n";
        }
        else{
            cout<< R << " + " <<I<<"i\n";
        }
}

void sub(Complex &obj1, Complex &obj2){
    int R = obj1.a-obj2.a;
    int I =obj1.b - obj2.b;
     if(I < 0){
            cout<< R << " - " <<I*(-1)<<"i\n";
        }
        else{
            cout<< R << " + " <<I<<"i\n";
        }
}

int main() {
    Complex c1(3,-2);
    Complex c2(1,2);

    c1.print();
    c2.print();

    add(c1,c2);
    sub(c1,c2);

    Complex c3 = c1 - c2;

    c3.print();

    
    return 0;
}