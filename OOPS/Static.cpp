#include <iostream>
using namespace std;

void counter(){
static int count = 0; //static Variables in a function are created & initialised once for the lifetime of the program 
count++;
cout << "The Count:"<< count <<"\n";
};

class Example {
public:
static int x;
};

int Example::x = 0;

class Object {
    public:
    Object(){
        cout <<"Constructor ...\n";
    }
    ~Object(){
        cout<<"Destructor ...\n";
    }
};

int main() {
    // Function
    counter();
    counter();
    counter();

    //Class
    Example eg1;
    Example eg2;
    Example eg3;

    cout << eg1.x++ <<"\n";
    cout << eg2.x++<<"\n";
    cout << eg3.x++<<"\n";

    //object
    int a = 0;
    cout << "Object 1\n";
    if(a==0){
        Object obj1;
    }
    cout << "code ended...\n";
cout << "Object 2\n";
    int b = 0;
    if(b == 0){
        static Object obj2;
    }
    cout << "Code ended ..\n";
    return 0;
}