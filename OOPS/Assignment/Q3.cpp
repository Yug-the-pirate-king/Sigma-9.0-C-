#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>

namespace {
    template <typename T>
    void printField(std::string_view label, const T& value) {
        std::cout << label << ": " << value << '\n';
    }
}

class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& name, int age) : name(name), age(age) {
        if (age < 0) {
            throw std::invalid_argument("Age cannot be negative");
        }
    }

    virtual ~Person() = default;

    virtual void print() const {
        printField("Name", name);
        printField("Age", age);
    }
};

class Student : public Person {
private:
    std::string student_id;
public:
    Student(const std::string& name, int age, const std::string& id)
        : Person(name, age), student_id(id) {
        if (id.empty()) {
            throw std::invalid_argument("Student ID cannot be empty");
        }
    }

    void print() const override {
        Person::print();
        printField("Student ID", student_id);
    }
};

int main() {
    Student s1("Yug", 20, "BS50");
    s1.print();
    return 0;
}