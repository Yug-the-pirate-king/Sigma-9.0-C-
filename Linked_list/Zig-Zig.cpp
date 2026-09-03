#include <iostream>
using namespace std;

/**
 * @brief Represents a single node in a singly linked list.
 *
 * Each node stores an integer value and a pointer to the next node.
 * The destructor recursively deletes the remainder of the list.
 */
class Node
{
public:
    int data;      ///< Value stored in this node.
    Node *next;    ///< Pointer to the next node in the list.

    /**
     * @brief Constructs a node with the given value.
     * @param val The integer value to store in the node.
     */
    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    /**
     * @brief Recursively destroys this node and all following nodes.
     */
    ~Node()
    {
        cout << "del Node " << data << "\n";
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
    }
};

/**
 * @brief Implements a singly linked list with various utility operations.
 */
class List
{
    Node *head;    ///< Pointer to the first node in the list.
    Node *tail;    ///< Pointer to the last node in the list.

public:
    /**
     * @brief Constructs an empty list.
     */
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief Destroys the list by deleting the head node.
     *
     * The Node destructor handles recursive deletion of the entire chain.
     */
    ~List()
    {
        if (head != nullptr)
        {
            cout << "Del List\n";
            delete head;
        }
    }

    /**
     * @brief Returns the head pointer of the list.
     * @return Pointer to the first node.
     */
    Node *getHead()
    {
        return head;
    }

    /**
     * @brief Updates the head pointer of the list.
     * @param newHead Pointer to the new head node.
     * @return Pointer to the updated head.
     */
    Node *setHead(Node *newHead)
    {
        head = newHead;
        return head;
    }

    /**
     * @brief Inserts a new value at the front of the list.
     * @param val The value to insert.
     */
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            // Empty list: new node is both head and tail.
            head = tail = newNode;
        }
        else
        {
            // Link the new node before the current head.
            newNode->next = head;
            head = newNode;
        }
    }

    /**
     * @brief Inserts a new value at the back of the list.
     * @param val The value to insert.
     */
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            // Empty list: new node is both head and tail.
            head = tail = newNode;
        }
        else
        {
            // Append the new node after the current tail.
            tail->next = newNode;
            tail = newNode;
        }
    }

    /**
     * @brief Inserts a new value after the node at position (pos - 1).
     * @param val The value to insert.
     * @param pos The target position; node is inserted after index pos - 1.
     *
     * @note A value of pos = 1 inserts after the head node.
     */
    void push(int val, int pos)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        // Traverse pos - 1 steps to reach the insertion point.
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "position is INVALID\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "position is INVALID\n";
            delete newNode;
            return;
        }

        // Insert the new node after temp.
        newNode->next = temp->next;
        temp->next = newNode;

        // Update tail if the new node was inserted at the end.
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    /**
     * @brief Prints the list from head to tail.
     */
    void print_ll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    /**
     * @brief Removes the front node of the list.
     */
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        // Move head forward and isolate the old front node.
        head = head->next;
        temp->next = nullptr;

        // If the list becomes empty, update tail as well.
        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete temp; // Properly free the isolated node.
    }

    /**
     * @brief Removes the back node of the list.
     */
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        // Single-node list: remove the only node.
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *temp = head;

        // Traverse to the node just before the tail.
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        // Isolate and delete the current tail.
        Node *nodeToDelete = tail;
        tail = temp;
        tail->next = nullptr;

        delete nodeToDelete;
    }

    /**
     * @brief Iteratively searches for a value and prints its zero-based index.
     * @param val The value to search for.
     */
    void searchi(int val)
    {
        Node *temp = head;
        int n = 0;

        // Scan the entire list, including the tail node.
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "Node " << n << "\n";
                return;
            }
            n++;
            temp = temp->next;
        }

        cout << "The Node with this val does not exist.\n";
    }

    /**
     * @brief Recursive helper for Search_re.
     * @param temp Current node being examined.
     * @param val Value to search for.
     * @return Zero-based index of the value, or -1 if not found.
     */
    int helper(Node *temp, int val)
    {
        if (temp == nullptr)
        {
            return -1;
        }

        if (temp->data == val)
        {
            return 0;
        }

        int idx = helper(temp->next, val);

        // Propagate -1 if the value was not found in the rest of the list.
        if (idx == -1)
        {
            return -1;
        }

        return idx + 1;
    }

    /**
     * @brief Recursively searches for a value and prints its index.
     * @param val The value to search for.
     */
    void Search_re(int val)
    {
        Node *temp = head;

        int result = helper(temp, val);
        if (result == -1)
        {
            cout << "The Node with this val does not exist.\n";
        }
        else
        {
            cout << "Node " << result << "\n";
        }
    }

    /**
     * @brief Reverses the entire list in-place.
     */
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextn = nullptr;

        // The current head will become the tail after reversal.
        tail = head;

        // Iteratively reverse the next pointers.
        while (current != nullptr)
        {
            nextn = current->next;   // Store the next node.
            current->next = prev;    // Reverse the link.
            prev = current;          // Move prev forward.
            current = nextn;         // Move current forward.
        }

        head = prev;
    }

    /**
     * @brief Recursively computes the length of a list chain.
     * @param temp Pointer to the start of the chain.
     * @return Number of nodes in the chain.
     */
    int sizelist(Node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }

        if (temp->next == nullptr)
        {
            return 1;
        }

        return 1 + sizelist(temp->next);
    }

    /**
     * @brief Removes the nth node from the end of the list.
     * @param n Zero-based index from the end of the list.
     */
    void Find_Remove(int n)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        int len = sizelist(head);

        // Validate n.
        if (n < 0 || n >= len)
        {
            cout << "Invalid position\n";
            return;
        }

        // If removing the head node.
        if (n == len - 1)
        {
            Node *temp = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            temp->next = nullptr;
            delete temp;
            return;
        }

        // Locate the node just before the target.
        Node *temp = head;
        for (int count = 0; count < len - n - 2; count++)
        {
            temp = temp->next;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        // Update tail if the removed node was the last node.
        if (nodeToDelete->next == nullptr)
        {
            tail = temp;
        }

        nodeToDelete->next = nullptr;
        delete nodeToDelete;
    }

    /**
     * @brief Splits a list into two halves at the middle.
     * @param head Pointer to the head of the list to split.
     * @return Pointer to the head of the right (second) half.
     *
     * Uses the slow/fast pointer technique. The left half ends at prev.
     */
    Node *splitAtMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        Node *prev = nullptr;

        // Fast pointer moves twice as fast as slow pointer.
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the link between the two halves.
        if (prev != nullptr)
        {
            prev->next = nullptr;
        }

        return slow;
    }

    /**
     * @brief Reverses a list chain and returns the new head.
     * @param head Pointer to the head of the chain.
     * @return Pointer to the new head after reversal.
     */
    Node *reverselist(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextn = nullptr;

        while (current != nullptr)
        {
            nextn = current->next;
            current->next = prev;
            prev = current;
            current = nextn;
        }

        return prev;
    }

    /**
     * @brief Merges two lists by alternating their nodes.
     * @param left Pointer to the head of the first list.
     * @param right Pointer to the head of the second list.
     *
     * Nodes are interleaved: left[0], right[0], left[1], right[1], ...
     */
    void altmerge(Node *left, Node *right)
    {
        if (left == nullptr || right == nullptr)
        {
            return;
        }

        while (left != nullptr && right != nullptr)
        {
            Node *templn = left->next;
            Node *temprn = right->next;

            left->next = right;

            if (templn == nullptr)
            {
                break;
            }

            right->next = templn;

            left = templn;
            right = temprn;
        }
    }

    /**
     * @brief Reorders the list in a zig-zag (alternate) pattern.
     * @param head Pointer to the head of the list.
     *
     * Splits the list at the middle, reverses the right half, and
     * alternately merges the two halves.
     */
    void zigzigll(Node *head)
    {
        // Split the list into two halves.
        Node *rightHead = splitAtMid(head);

        // Reverse the right half.
        Node *rightrev = reverselist(rightHead);

        // Merge the two halves alternately.
        altmerge(head, rightrev);
    }
};

/**
 * @brief Entry point: demonstrates list construction and zig-zag reordering.
 */
int main()
{
    List ll;

    // Build the list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print_ll();

    // Reorder the list in zig-zag fashion.
    ll.zigzigll(ll.getHead());

    ll.print_ll();

    return 0;
}