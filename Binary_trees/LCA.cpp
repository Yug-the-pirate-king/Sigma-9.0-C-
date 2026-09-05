#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

bool rootToNodePath(Node *root, int n, vector<int> &path)
{
    if (root == nullptr)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }

    if (rootToNodePath(root->left, n, path) || rootToNodePath(root->right, n, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n2, path1);
    rootToNodePath(root, n1, path2);
    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[i])
        {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}


int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    int n1 = 4,n2= 5;

    cout << LCA(root,n1,n2);
    return 0;
}