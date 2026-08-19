#include <iostream>
#include <vector>
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

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return nullptr;
    Node *currnode = new Node(nodes[idx]);
    currnode->left = buildTree(nodes);
    currnode->right = buildTree(nodes);
    return currnode;
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int diaml(Node *root)
{
    if (root == nullptr)
    {
        return 0; 
    }
    int currdiaml = height(root->left) + height(root->right) + 1;
    int leftDiaml = diaml(root->left);
    int rightDiaml = diaml(root->right);
    return max(currdiaml, max(leftDiaml, rightDiaml));
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    cout << diaml(root);
    return 0;
}