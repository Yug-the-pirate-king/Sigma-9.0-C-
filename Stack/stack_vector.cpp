#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Stack
{
public:
    int top = -1;
    vector<int> stackvector;

    void push(int val)
    {
        stackvector.push_back(val);
        top++;
    }
    void pop()
    {
        if (top != -1)
        {
            stackvector.pop_back();
            top--;
        }
        else
        {
            cout << "underflow";
        }
    }

    int topstack()
    {
        return stackvector[top];
    }

    bool isEmpty()
    {
        if (top <= -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Home work
int arr[100];
class Stack2
{
public:
    int top = -1;
    Stack2() 
    {
        fill(begin(arr), end(arr), -1);
    }

    void push(int val){
        if(top == 100){
            cout << "overflow";
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top <= -1){
            cout << "underflow";
        }
        arr[top] = -1;
        top--;
    }

    int topval(){
        return arr[top];
    }

    bool isempty(){
        if(top <= -1){
            return true;
        }

        return false;
    }
};
int main()
{
    Stack s;
    cout << "Stack using Vector\n";
    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.topstack() << " ";
        s.pop();
    }
    cout << "\n";
    cout << "Stack using arr\n";
    Stack2 s2;

    s2.push(3);
    s2.push(2);
    s2.push(1);

    while (!s2.isempty())
    {
        cout << s2.topval() << " ";
        s2.pop();
    }


    return 0;
}