#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node *buildTreeHelper(const vector<int> &nodes, size_t &idx)
{
    if (idx >= nodes.size())
    {
        throw runtime_error("Invalid tree serialization: not enough nodes");
    }
    int val = nodes[idx++];
    if (val == -1)
        return nullptr;
    Node *currnode = new Node(val);
    currnode->left = buildTreeHelper(nodes, idx);
    currnode->right = buildTreeHelper(nodes, idx);
    return currnode;
}

Node *buildTree(const vector<int> &nodes)
{
    size_t idx = 0;
    return buildTreeHelper(nodes, idx);
}

bool isIdentical(Node *root, Node *subroot)
{
    if (root == nullptr && subroot == nullptr)
        return true;
    if (root == nullptr || subroot == nullptr)
        return false;
    if (root->data != subroot->data)
        return false;
    return isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}

bool isSubtree(Node *root, Node *subroot)
{
    if (subroot == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (root->data == subroot->data && isIdentical(root, subroot))
        return true;
    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = nullptr;
    Node *subroot = nullptr;

    try
    {
        root = buildTree(nodes);

        subroot = new Node(2);
        subroot->left = new Node(4);
        subroot->right = new Node(5);

        cout << isSubtree(root, subroot) << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        deleteTree(root);
        deleteTree(subroot);
        return 1;
    }

    deleteTree(root);
    deleteTree(subroot);
    return 0;
}