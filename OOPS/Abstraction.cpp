#include <iostream>
using namespace std;

//abstract class
class shape
{
public:
virtual void draw()=0 ;// pure virtual function
};

class Circle : public shape{
    public:
    void draw(){
        cout << "Draw Circle.\n";
    }
};

class Square : public shape{
    public:
    void draw(){
        cout << "Draw Square.\n";
    }
};



int main() {
    Circle c1;
    c1.draw();
    Square s1;
    s1.draw();

    
    return 0;
}