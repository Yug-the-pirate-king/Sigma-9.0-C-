#include <iostream>
#include <vector>
#include<algorithm>
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

pair<int, int> diaml(Node *root)
{
    if(root == nullptr){ 
        return make_pair(0,0);
    }
    pair<int,int> leftinfo = diaml(root->left);
    pair<int,int> rightinfo = diaml(root->right);

    int curr = leftinfo.second + rightinfo.second + 1;
    int finalDiam = max(curr,max(leftinfo.first,rightinfo.first));
    int finalhit = 1 + max(leftinfo.second,rightinfo.second);

    return make_pair(finalDiam,finalhit);

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    pair<int,int> ans = diaml(root);
    cout << ans.first;
    return 0;
}