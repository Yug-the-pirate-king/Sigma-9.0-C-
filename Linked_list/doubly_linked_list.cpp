#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int Val)
    {
        data = Val;
        next = nullptr;
        prev = nullptr;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front(){
        if (head == nullptr)
        {
            cout << "Underflow\n";
        }
        else{
            cout << head->data <<"\n";
            Node* temp = head;
            head = head->next;
           if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_back(){
         if (head == nullptr)
        {
            cout << "Underflow\n";
        }
        else{
            cout << tail->data <<"\n";
            Node* temp = tail;
            tail = tail->prev;
           if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        }
    }
};


int main()
{
    List ll;

    ll.push_front(1);
    ll.push_back(2);
    ll.pop_front();
    ll.pop_back();


    return 0;
}