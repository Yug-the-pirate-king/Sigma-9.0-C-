#include <iostream>
#include<vector>
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
bool isIdentical(Node* root, Node* subroot){
    if(root == nullptr && subroot == nullptr){
        return true;
    }
    if(root == nullptr || subroot == nullptr){
        return false;
    }
    if(root->data != subroot->data){
        return false;
    }
    return isIdentical(root->left,subroot->left) && isIdentical(root->right,subroot->right);
}

bool isSubtree(Node* root,Node*subroot){
    if(root->data == subroot->data){
        if(isIdentical(root,subroot)){
            return true;
        }else{
            return false;
        }
    }
    bool leftsubtree = isSubtree(root->left,subroot);
    if(! leftsubtree){
        return isSubtree(root->right,subroot);
    }
    return leftsubtree;

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);

    cout << isSubtree(root, subroot) << endl;

    return 0;
}