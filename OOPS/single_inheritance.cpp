#include <iostream>
#include <string>

class Animal {
public:
    std::string color;

    void eat() const {
        std::cout << "eats\n";
    }

    void breathe() const {
        std::cout << "breathes\n";
    }
};

class Fish : public Animal {
public:
    int finCount = 6;

    void swim() const {
        std::cout << "swims\n";
    }
};

class Bird : protected Animal {
public:
    void fly() const {
        eat();
        std::cout << "fly\n";
    }
};

int main() {
    Fish fish;
    Bird bird;

    std::cout << fish.finCount << '\n';
    fish.eat();
    fish.breathe();
    fish.swim();

    bird.fly();

    return 0;
}