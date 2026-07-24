#include <iostream>
#include <deque>
using namespace std;

class Stack
{
    deque<int> deq;

public:
    void push(int data)
    {
        deq.push_front(data);
    }

    void pop()
    {
        if (deq.empty())
        {
            cout << "Underflow";
            return;
        }
        deq.pop_front();
    }

    int top()
    {
        if (deq.empty())
        {
            return -1;
        }
        return deq.front();
    }

    void print()
    {
        deque<int> d = deq;
        while (!d.empty())
        {
            cout << d.front() << "|";
            d.pop_front();
        }

        cout << "\n";
    }
};

int main()
{
    Stack Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);

    Q.print();

    Q.pop();
    Q.pop();
    Q.pop();

    Q.print();

    cout << Q.top();

    return 0;
}