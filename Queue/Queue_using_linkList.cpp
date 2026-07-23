#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    {
        if (head == nullptr)
        {
            cout << "underflow";
            return;
        }
        else
        {
            head = head->next;
            print_Queue();
        }
    }
    int front()
    {
        if (head == nullptr)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    bool empty()
    {
        if (head == nullptr)
        {
            return false;
        }
        return true;
    }
    void print_Queue()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << "\n";
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
    cout << q1->front() << "\n";

    return 0;
}