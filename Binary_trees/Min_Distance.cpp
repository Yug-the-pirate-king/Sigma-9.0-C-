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
bool isIdentical(Node *root, Node *subroot)
{
    if (root == nullptr && subroot == nullptr)
    {
        return true;
    }
    if (root == nullptr || subroot == nullptr)
    {
        return false;
    }
    if (root->data != subroot->data)
    {
        return false;
    }
    return isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    return (left == nullptr) ? right : left;
}

int Distance(Node* root,int n){
    if(root == nullptr){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    return 1+max(Distance(root->left,n),Distance(root->right,n));
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    int n1= 5,n2 = 6;
    Node* LCAnode = LCA(root,n1,n2);
    
    cout << Distance(LCAnode,n1) + Distance(LCAnode,n2);
    return 0;
}