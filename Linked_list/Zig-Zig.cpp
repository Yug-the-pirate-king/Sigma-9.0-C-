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

    Node* reverselist(Node* head){
        
        Node *prev = NULL;
        Node *current = head;
        Node *nextn;

        while (current != NULL)
        {
            nextn = current->next;
            current->next = prev;
            prev = current;
            current = nextn;
        }
         
        return prev;
    }

    void altmerge(Node* left,Node* right){
    if (left == nullptr || right == nullptr) return;

    while (left != nullptr && right != nullptr) {
        Node* templn = left->next;
        Node* temprn = right->next;

        left->next = right;
        
        if (templn == nullptr) {
            break;
        }
        right->next = templn;

        left = templn;
        right = temprn;
    }
    }

    void zigzigll(Node* head){

        Node* rightHead = sqlitAtMid(head);
        Node* rightrev = reverselist(rightHead);

        altmerge(head,rightrev);

    }
};

int main() {

    List ll;
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print_ll();

    ll.zigzigll(ll.getHead());

    ll.print_ll();
    
    return 0;
}