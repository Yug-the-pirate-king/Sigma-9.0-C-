#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return root;
    }

    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *BuildBST(int roots[], int n)
{
    Node *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, roots[i]);
    }

    return root;
}

void printInorde(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorde(root->left);
    cout << root->val << " ";
    printInorde(root->right);
}

void printPreorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

bool search(Node *root, int val)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == val)
    {
        return true;
    }

    if (root->val > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

Node *getInorderSuccessor(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
    {
        return NULL;
    }

    if (val < root->val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return NULL;
        }

        if (root->left == nullptr || root->right == nullptr)
        {
            return root->left == NULL ? root->right : root->left;
        }

        Node *IS = getInorderSuccessor(root->right);
        root->val = IS->val;
        root->right = deleteNode(root->right, IS->val);
        return root;
    }

    return root;
}

void printRange(Node *root, int start, int end)
{
    if (root == nullptr)
    {
        return;
    }
    if (start <= root->val && root->val <= end)
    {
        cout << root->val << " ";
        printRange(root->left, start, end);
        printRange(root->right, start, end);
    }

    if (start < root->val)
    {
        printRange(root->left, start, end);
    }

    if (root->val < start)
    {
        printRange(root->right, start, end);
    }
}

void printvector(vector<int> &ans)
{
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void printpath(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    ans.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {
        printvector(ans);
    }
    else
    {
        printpath(root->left, ans);
        printpath(root->right, ans);
    }

    ans.pop_back();
}

bool isBST(Node *root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX)
{
    if (root == nullptr) return true;

    if (root->val <= minVal || root->val >= maxVal)
    {
        return false;
    }

    return isBST(root->left, minVal, root->val) && 
           isBST(root->right, root->val, maxVal);
}
Node* BuildBSTSort(int roots[],int st,int end){
    if(st > end){
        return nullptr;
    }
    int mid = st + (end-st)/2;
    Node* temp = new Node(roots[mid]);
    temp->left = BuildBSTSort(roots,st,mid-1);
    temp->right = BuildBSTSort(roots,mid+1,end);

    return temp;
}

void InorderStore(Node* root, vector<Node*>& arr){
    if(root == nullptr){
        return;
    }
    InorderStore(root->left,arr);
    arr.push_back(root);
    InorderStore(root->right,arr);
}

Node* BulidBSTSortNodes(vector<Node*> roots,int st,int end){
if(st > end){
    return nullptr;
}
int mid = st +(end-st)/2;
Node* temp = roots[mid];
temp->left = BulidBSTSortNodes(roots,st,mid-1);
temp->right = BulidBSTSortNodes(roots,mid+1,end);
return temp;

}



int main()
{

    // int arr[6] = {5, 1, 3, 4, 2, 7};
    // Node *root = BuildBST(arr, 6);

    // printInorde(root);

    // cout << "\n";

    // if(search(root, 11)){
    //     cout << "Found";
    // }else{
    //     cout << "Not Found";
    // }

    // deleteNode(root,4);

    // printInorde(root);

    // cout << "\n";

    // cout << "The Number in the range 5 and 10 in the tree are : ";
    // printRange(root,5,10);

    // cout << "\n";

    // cout << "Path : \n";
    // vector<int> ans;
    // printpath(root,ans);

    // if (isBST(root))
    // {
    //     cout << "True";
    // }
    // else
    // {
    //     cout << "False";
    // }

    // int arr[] ={3,4,5,6,7,8,9};
    // Node* root1 = BuildBSTSort(arr, 0,6);
    // printInorde(root1);

    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<Node*> arr;
    InorderStore(root,arr);
    Node* root1 = BulidBSTSortNodes(arr,0,arr.size()-1);
    printPreorder(root1);
    return 0;
}