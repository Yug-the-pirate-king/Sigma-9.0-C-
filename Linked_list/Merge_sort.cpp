#include <iostream>
#include <List>
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
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
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
        if (head != NULL)
        {
            cout << "Del List\n";
            delete head;
        }
    }

    Node *getHead()
    {
        return head;
    }

    Node *setHead(Node *newHead)
    {
        head = newHead;
        return head;
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

    void push(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "position is INVALID\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        temp->~Node();
    }

    void pop_back()
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        tail->next = NULL;
        temp->~Node();
    }

    void searchi(int val)
    {
        Node *temp = head;
        int n = 0;
        while (temp->next != NULL)
        {
            if (temp->data == val)
            {
                cout << "Node " << n << "\n";
                return;
            }
            n++;
            temp = temp->next;
        }

        cout << "The Node with this val does not exist.";
    }

    int helper(Node *temp, int val)
    {
        if (temp == NULL)
        {
            return -1;
        }

        if (temp->data == val)
        {
            return 0;
        }

        int idx = helper(temp->next, val) + 1;

        return idx;
    }

    void Search_re(int val)
    {
        Node *temp = head;

        cout << "Node " << helper(temp, val) << "\n";
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *nextn;

        tail = head;

        while (current != NULL)
        {
            nextn = current->next;
            current->next = prev;
            prev = current;
            current = nextn;
        }

        head = prev;
    }

    int sizelist(Node *temp)
    {
        if (temp->next == NULL)
        {
            return 1;
        }
        int idx = sizelist(temp->next) + 1;

        return idx;
    }

    void Find_Remove(int n)
    {
        Node *temp = head;
        int len = sizelist(temp);
        int count = 1;

        while (count != (len - n))
        {
            temp = temp->next;
            count++;
        }

        temp->next = temp->next->next;
    }
};

Node *sqlitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != nullptr)
    {
        prev->next = nullptr;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (left != nullptr && right != nullptr)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
            temp->next = nullptr;
        }
    }

    if (left != nullptr)
    {
        temp->next = left;
    }
    else
    {
        temp->next = right;
    }

    return dummy->next;
    delete dummy;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *mid = sqlitAtMid(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(mid);

    return merge(left, right);
}

int main()
{
    List ll;
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(1);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(6);

    // 1->2->3->4->5->6

    ll.print_ll();

    Node *sortedHead = mergeSort(ll.getHead());
    ll.setHead(sortedHead);

    ll.print_ll();

    return 0;
}