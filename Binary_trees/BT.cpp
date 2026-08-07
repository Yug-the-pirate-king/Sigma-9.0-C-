#include <iostream>
#include <vector>
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

/*BFS (Breadth-First Search) and DFS (Depth-First Search)
are broad strategies to traverse trees or graphs. In-order,
pre-order, and post-order are specific types of DFS used for binary trees,
categorized by when you visit the root node relative to its subtrees */

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    Q.push(nullptr);

    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();
        if (curr == nullptr)
        {
            cout << endl;
            if (Q.empty())
            {
                break;
            }
            Q.push(nullptr);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != nullptr)
            {
                Q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                Q.push(curr->right);
            }
        }
    }
}

int height(Node *root)
{
    if (root == nullptr) {return 0;}
    return max(height(root->left), height(root->right)) + 1;
}

int count(Node *root){
    if(root == nullptr) {return 0;}
    return count(root->left) + count(root->right) + 1;
}

int sum(Node *root){
if(root == nullptr) {return 0;}
    return sum(root->left) + sum(root->right) + root->data;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = buildTree(nodes);
    idx = -1;
    Node *root2 = buildTree(nodes2);

    cout << "Root = " << root->data << "\n";

    // root -> left -> right

    preOrder(root);
    cout << "\n";

    // left -> root -> right

    InOrder(root);
    cout << "\n";

    // left -> right -> root

    postOrder(root);
    cout << "\n";

    levelOrder(root);

    cout << "height of nodes : "<< height(root) << "\n";
    cout << "height of nodes2 : " << height(root2) << "\n";

    cout << "The number of nodes in nodes : " << count(root);
    cout << endl;
    cout << "The sum of data in nodes : " << sum(root);

    return 0;
}