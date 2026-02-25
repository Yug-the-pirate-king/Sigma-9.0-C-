#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
};

class Student :public Person{
private:
string student_id;
public:
Student(string name,int age,string id):Person(name,age){
    this->student_id=id;
}

void print(){
    cout << "Name: "<<name<<"\n";
    cout << "Age: "<<age<<"\n"; 
    cout << "Student ID: "<<student_id<<"\n";
}
};

int main() {
    Student s1("Yug",20,"BS50");

    s1.print();
    return 0;
}