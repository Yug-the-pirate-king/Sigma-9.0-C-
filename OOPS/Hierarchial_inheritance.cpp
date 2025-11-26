#include <iostream>
#include<string>
using namespace std;

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

class Mammal : public Animal {
    public:
    string bloodType;

    Mammal(){
        bloodType = "Warm";
    }
};

class fish : public Animal {
    public:
    string bloodType;

    fish(){
        bloodType = "cold";
    }
};

class Dog : public Mammal{
    public:
    void tailwag(){
        cout <<"A dog wag its tail.\n";
    }
};


int main() {
Dog d1;

d1.eat();
d1.breathe();
d1.tailwag();
cout << d1.bloodType;
    return 0;
}