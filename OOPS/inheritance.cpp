#include <iostream>
#include <string>

class Car {
public:
    std::string brand;
    std::string color;
    int mileage;

    Car() : brand(), color(), mileage(0) {
        std::cout << "Constructor without parameter\n";
    }

    Car(const std::string& brandName, const std::string& bodyColor)
        : brand(brandName), color(bodyColor), mileage(12) {
        std::cout << "Constructor with parameter\n";
    }

    Car(const Car& other)
        : brand(other.brand), color(other.color), mileage(other.mileage) {
        std::cout << "Copy Constructor called\n";
    }

    void startEngine() const {
        std::cout << "Car has started.";
    }

    void stopEngine() const {
        std::cout << "Car has stopped.";
    }
};

int main() {
    Car c1("Bmw", "white");
    Car c2(c1);
    std::cout << c2.brand << '\n';
    std::cout << c2.color << '\n';
    return 0;
}