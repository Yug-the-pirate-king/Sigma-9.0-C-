#include <iostream>
#include <string>
using namespace std;

// Helper that prints a message followed by a newline.
// This removes duplicated cout logic across the animal classes.
inline void printAction(const string& action) {
    cout << action << '\n';
}

// Base class representing a generic animal.
class Animal {
public:
    string color;

    // Prints that the animal eats.
    void eat() const {
        printAction("eats");
    }

    // Prints that the animal breathes.
    void breathe() const {
        printAction("breathes");
    }
};

// Shared intermediate class for animals that have a blood type.
// This avoids repeating the bloodType member in every derived class.
class BloodedAnimal : public Animal {
public:
    string bloodType;

    // Stores the given blood type for the animal.
    explicit BloodedAnimal(const string& type) : bloodType(type) {}
};

// Mammal: a warm-blooded animal.
class Mammal : public BloodedAnimal {
public:
    Mammal() : BloodedAnimal("Warm") {}
};

// Fish: a cold-blooded animal.
class Fish : public BloodedAnimal {
public:
    Fish() : BloodedAnimal("cold") {}
};

// Dog: a mammal with a tail-wagging behavior.
class Dog : public Mammal {
public:
    // Prints that the dog wags its tail.
    void tailwag() const {
        printAction("A dog wag its tail.");
    }
};

// Runs the same demonstration sequence as the original main().
void demonstrateDog(Dog& dog) {
    dog.eat();              // Inherited from Animal via Mammal.
    dog.breathe();          // Inherited from Animal via Mammal.
    dog.tailwag();          // Specific to Dog.
    cout << dog.bloodType;  // Inherited warm blood type.
}

int main() {
    Dog d1;
    demonstrateDog(d1);
    return 0;
}