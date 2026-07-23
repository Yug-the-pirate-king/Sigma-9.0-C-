#include <iostream>
#include <vector>
using namespace std;
class Queue
{
    int *arr;
    int capacity;
    int currsize;
    int f, r;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currsize = 0;
        f = r = -1;
    }

    void push(int data)
    {
        if (currsize == capacity)
        {
            cout << "overflow_error";
            return;
        }
        if (empty()) {
            f = 0;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currsize++;
        
    }

    void pop()
    {
        if (empty())
        {
            cout << "underflow_error";
            return;
        }
        f = (f + 1) % capacity;
        currsize--;

        if (currsize == 0) {
            f = -1;
            r = -1;
        }
    }

    int front()
    {
        if (empty())
        {
            cout << "underflow_error";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        if (currsize == 0)
        {
            return true;
        }
        return false;
    }
    void print_Queue()
    {
        if (f == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        int t = f;
        while (true)
        {
            cout << arr[t] << "|";

            // If we just printed the rear element, stop the loop safely
            if (t == r)
            {
                break;
            }

            // Move to the next index circularly
            t = (t + 1) % capacity;
        }
        cout << "\n";
    }
};
int main()
{
    Queue *q1 = new Queue(5);
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
}