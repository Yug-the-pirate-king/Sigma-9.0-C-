#include <iostream>
#include <string>
using namespace std;

class Car{

    public:
    string name;
    string color;
    int *mileage;
    Car(){
        cout <<"Constructor without parameter\n";
    }
    Car(string name,string color){
        cout <<"Constructor with parameter\n";
        this->name = name;
        this->color = color;
        mileage = new int;
        *mileage = 12;
    }
    Car(Car &obj){ //copy constructor
        cout <<"Copy Constructor called\n";
        name = obj.name;
        color = obj.color;
        //mileage = obj.mileage; // shallow copy
        mileage = new int; //deep copy
        *mileage = *(obj.mileage);
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
    Car c2(c1); //defult copy
    cout << c2.name<<"\n";
    cout << c2.color<<"\n";
    return 0;
}