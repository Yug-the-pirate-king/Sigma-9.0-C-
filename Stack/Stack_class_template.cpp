#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <class T>

class Stack
{
public:
    int top = -1;
    vector<T> stackvector;

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

    T topstack()
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

int main()
{
    Stack<char> s;
    s.push('C');
    s.push('B');
    s.push('A');

    while (!s.isEmpty())
    {
        cout << s.topstack() << " ";
        s.pop();
    }

    return 0;
}