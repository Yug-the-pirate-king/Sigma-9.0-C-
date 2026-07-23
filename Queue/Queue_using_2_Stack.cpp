#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> stack1;
    stack<int> stack2;

public:
    Queue()
    {
    }
    void push(int data)
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(data);
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "underflow";
            return;
        }
        stack1.pop();
    }

    int front()
    {
        if (empty())
        {
            return -1;
        }
        return stack1.top();
    }

    void print_Queue()
    {
        // print from front to back (top to bottom of stack1)
        stack<int> temp = stack1;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "\n";
    }

    bool empty()
    {
        if (stack1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue *q1 = new Queue();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    q1->print_Queue();
    q1->pop();
    q1->print_Queue();
    cout << q1->front() << "\n";
    return 0;
    return 0;
}