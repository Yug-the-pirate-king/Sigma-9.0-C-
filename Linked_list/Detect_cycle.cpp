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

    bool isCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << "Cycle exists";
                return true;
            }
        }
        cout << "Cycle does not exists";
        return false;
    }

    void removing_cycle(Node *head)
    {
        if (head == NULL)
            return;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;

                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                Node *temp = slow;
                while (temp->next != slow)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
                return;
            }
        }
    }
};
;

int main()
{
    List ll;

    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout << "List before creating cycle: ";
    ll.print_ll();

    ll.tail->next = ll.head;

    if (ll.isCycle(ll.head))
    {
        ll.removing_cycle(ll.head);
        cout << "List after removing cycle: ";
        ll.print_ll();
    }

    return 0;
}