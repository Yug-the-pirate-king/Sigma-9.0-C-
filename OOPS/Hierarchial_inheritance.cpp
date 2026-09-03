#include <iostream>
#include <string>
#include <stdexcept>

class Animal {
public:
    Animal() = default;
    virtual ~Animal() = default;

    explicit Animal(const std::string& color) : color_{color} {
        validateColor(color_);
    }

    void setColor(const std::string& color) {
        validateColor(color);
        color_ = color;
    }

    [[nodiscard]] const std::string& color() const noexcept {
        return color_;
    }

    void eat() const {
        std::cout << "eats\n";
    }

    void breathe() const {
        std::cout << "breathes\n";
    }

private:
    std::string color_;

    static void validateColor(const std::string& color) {
        if (color.empty()) {
            throw std::invalid_argument("Animal color cannot be empty");
        }
    }
};

class Mammal : public Animal {
public:
    Mammal() = default;
    virtual ~Mammal() = default;

    explicit Mammal(const std::string& bloodType) : bloodType_{bloodType} {
        validateBloodType(bloodType_);
    }

    void setBloodType(const std::string& bloodType) {
        validateBloodType(bloodType);
        bloodType_ = bloodType;
    }

    [[nodiscard]] const std::string& bloodType() const noexcept {
        return bloodType_;
    }

private:
    std::string bloodType_{"Warm"};

    static void validateBloodType(const std::string& bloodType) {
        if (bloodType.empty()) {
            throw std::invalid_argument("Mammal blood type cannot be empty");
        }
    }
};

class Fish : public Animal {
public:
    Fish() = default;
    virtual ~Fish() = default;

    explicit Fish(const std::string& bloodType) : bloodType_{bloodType} {
        validateBloodType(bloodType_);
    }

    void setBloodType(const std::string& bloodType) {
        validateBloodType(bloodType);
        bloodType_ = bloodType;
    }

    [[nodiscard]] const std::string& bloodType() const noexcept {
        return bloodType_;
    }

private:
    std::string bloodType_{"cold"};

    static void validateBloodType(const std::string& bloodType) {
        if (bloodType.empty()) {
            throw std::invalid_argument("Fish blood type cannot be empty");
        }
    }
};

class Dog : public Mammal {
public:
    void tailwag() const {
        std::cout << "A dog wag its tail.\n";
    }
};

int main() {
    try {
        Dog d1;
        d1.setColor("Brown");
        d1.eat();
        d1.breathe();
        d1.tailwag();
        std::cout << d1.bloodType();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}