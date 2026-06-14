#include <iostream>
#include <list>
using namespace std;

template <class T>
class Stack
{
    list<T> ll;

public:
    void push(T val)
    {
        ll.push_front(val);
    }

    void pop()
    {
        ll.pop_front();
    }

    T top()
    {
        return ll.front();
    }

    bool isEmpty()
    {
        return ll.size() == 0;
    }
};

template <class T>
class Node
{
public: // FIX 1: Make variables public so Stackclass can access them
    T val;
    Node<T> *next;

    Node(T val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

template <class T>
class Stackclass
{
public:
    Node<T> *head;

    Stackclass()
    {
        head = nullptr;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        // FIX 2: Insert at the HEAD instead of the TAIL (O(1) time complexity)
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (head == nullptr)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    T top()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return T(); // Return default value of T
        }
        return head->val;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    Stack<int> ll;
    ll.push(3);
    ll.push(2);
    ll.push(1);

    while (!ll.isEmpty())
    {
        cout << ll.top() << " ";
        ll.pop();
    }

    // Stackclass
    cout << "\n";
    Stackclass<char> c;
    c.push('C');
    c.push('B');
    c.push('A');

    while (!c.isEmpty())
    {
        cout << c.top() << " ";
        c.pop();
    }

    return 0;
}