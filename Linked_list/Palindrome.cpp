#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr) {
        return true;
    }

        Node *mid = head;
        Node *last = head;

        while (last != nullptr && last->next != nullptr)
        {
            mid = mid->next;
            last = last->next->next;
        }

         Node *prev = NULL;
        Node *current = mid;
        Node *nextn;

        while (current != NULL)
        {
            nextn = current->next;
            current->next = prev;
            prev = current;
            current = nextn;
        }

      Node *left = head; 
        Node *right = prev; 

        while (right != nullptr)
        {
            if (left->data != right->data)
            {
                return false; 
            }
            left = left->next;   
            right = right->next; 
        }

        return true;
    }
};

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout<< ll.isPalindrome();

    return 0;
}