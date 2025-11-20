#include <iostream>
#include <string>
using namespace std;

class Teacher {
    public :
    int salary;
    string Subject;
};

class Student{
    public:
    int Roll_number;
    float cgpa;
};

class TA : public Teacher,public Student{
    public:
    string name;
};

int main() {
    
    TA tal;
    tal.cgpa = 10;
    tal.name = "Yug";
    tal.Roll_number=50;
    tal.salary = 5000000;
    tal.Subject ="Math";

    cout << "Name: " << tal.name << "\n";
    cout << "Roll Number: " << tal.Roll_number << "\n";
    cout << "CGPA: " << tal.cgpa << "\n";
    cout << "Salary: " << tal.salary << "\n";
    cout << "Subject: " << tal.Subject << "\n";
    return 0;
}
