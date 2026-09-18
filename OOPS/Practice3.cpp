#include <iostream>
using namespace std;

class Base {
public:
    // Virtual destructor ensures derived-class destructors are invoked
    // when an object is deleted through a base-class pointer.
    virtual ~Base() = default;

    virtual void print() {
        cout << "Base\n";
    }
};

class Derived : public Base {
public:
    // 'override' guarantees this function overrides a base-class virtual.
    void print() override {
        cout << "Derived\n";
    }
};

int main() {
    // Create a Derived object but refer to it through a Base pointer.
    Base* b = new Derived();

    // Dynamic dispatch calls Derived::print() at runtime.
    b->print();

    // Safe deletion through base pointer because Base's destructor is virtual.
    delete b;

    return 0;
}