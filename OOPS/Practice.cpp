#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
    int id;
    int password;

    public:
    string username;
    Employee(int id){
        this->id = id;
    }
    //setter
    void SetPassword(int password){
        this->password = password;
    }

    //Getter
    int GetSetter(){
        cout <<this->password;
    }
};

int main() {

    return 0;
}