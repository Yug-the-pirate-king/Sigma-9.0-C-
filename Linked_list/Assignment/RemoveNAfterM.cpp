#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        cout << "del Node " << data << "\n";
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        cout << "Del List\n";
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    Node *getHead()
    {
        return head;
    }

    Node *getNode(int pos)
    {
        Node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            if (temp == nullptr)
            {
                return nullptr;
            }
            temp = temp->next;
        }
        return temp;
    }

    Node *getTail()
    {
        return tail;
    }

    void setTail(Node *newTail)
    {
        tail = newTail;
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

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print_ll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void pop_front()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail; // Use delete
        tail = temp;
        tail->next = NULL;
    }

    void RemoveNAfterM(int n, int m)
    {
        int countm = 1;
        Node *lastM = head;
        int countn = 0;

        while (countm != m)
        {
            lastM = lastM->next;
            countm++;
        }

        Node* startN = lastM->next;

        while(countn != n){
            Node* prev = startN;
            startN = startN->next;
            prev->next = nullptr;
            countn++;
            delete(prev);
        }

        lastM->next = startN;
        
    }
};

int main()
{
    List *ll1 = new List();

    ll1->push_back(1);
    ll1->push_back(2);
    ll1->push_back(3);
    ll1->push_back(4);
    ll1->push_back(5);
    ll1->push_back(6);
    ll1->push_back(7);
    ll1->push_back(8);
    ll1->push_back(9);

    ll1->print_ll();

    ll1->RemoveNAfterM(2,3);

    ll1->print_ll();

    delete ll1;
    return 0;
}