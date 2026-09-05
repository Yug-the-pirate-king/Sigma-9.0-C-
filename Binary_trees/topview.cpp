#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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


void topview(Node* root){
    queue<pair<Node*,int>> Q; // node,hd
    map<int,int> m;

    Q.push(make_pair(root,0));
    while(!Q.empty()){
        pair<Node*,int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHd = curr.second;

        if(m.count(currHd) == 0){
            m[currHd] = currNode->data;
        }

        if(currNode->left != nullptr){
            pair<Node*,int> left = make_pair(currNode->left,currHd-1);
            Q.push(left);
        }

        if(currNode->right != nullptr){
            pair<Node*,int> right = make_pair(currNode->right,currHd+1);
            Q.push(right);
        }
    }

    for(auto it:m){
        cout << it.second<<" ";
    }

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    topview(root);

    return 0;
}