#include <iostream>
#include <string>
using namespace std;

class Car{
    string name;
    string color;

    public:
    Car(string nameval,string colorval){
        name = nameval;
        color = colorval;
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