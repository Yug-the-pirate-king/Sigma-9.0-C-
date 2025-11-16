#include <iostream>
#include <string>
using namespace std;

class Car{
    string name;
    string color;

    public:
    Car(){
        cout <<"Constructor without parameter";
    }
    Car(string name,string color){
        cout <<"Constructor with parameter";
       this->name = name;
        this->color = color;
    }
    void start(){
        cout << "Car has started.";
    }
    void stop(){
        cout << "Car has stopped.";
    }
};

int main() {
    Car c1("Bmw","white");
    return 0;
}