#include <iostream>
#include <string>
using namespace std;

// example of simple inheritance 

class Animal{
    public:
    string color;
    void eat(){
        cout << "eats\n";
    }
    void breathe(){
        cout <<"breathes\n";
    }
};

class Fish : public Animal{ // this is inheritance and its the mode is public(can be acesses in main)
public:
int fins = 6;

void swin(){
    cout << "Swins\n";
}
};

class Bird : protected Animal{ // this is inheritance and its the mode is protected(Can only acesses in the class)
public:

void fly(){
    eat();
    cout << "fly\n";
}
};


int main() {
   Fish f1;
   Bird b1;
   cout << f1.fins<<"\n";
    f1.eat();
    f1.breathe();
    f1.swin();

    //bird
    b1.fly();

    return 0;
}