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
};

void Kth(Node *root, int i, int target)
{
    if(root == nullptr){
        return;
    }
    if (target == i)
    {
        cout << root->data << " ";
        return;
    }
    
        Kth(root->left,i+1,target);
        Kth(root->right,i+1,target);
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    Kth(root,1,3);

    return 0;
}