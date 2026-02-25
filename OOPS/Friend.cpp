#include <iostream>
#include <string>
using namespace std;

class A{
    string secret = "sercret data";
    friend class B;
};

class B {
public :
void showSecret(A &obj){
    cout << obj.secret <<"\n";
}
};


int main() {
A a1;
B b1;

b1.showSecret(a1);
    return 0;
}