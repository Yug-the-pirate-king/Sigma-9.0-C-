/*
Question:
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Explanation:
- We are using two stacks, one for the left traversal and one for the right traversal of the BST.
- The next() function returns the next smallest element in the BST by popping the top element from the left stack and pushing all the leftmost nodes in its right subtree to the stack.
- The before() function returns the next largest element in the BST by popping the top element from the right stack and pushing all the rightmost nodes in its left subtree to the stack.
- We use the two pointer approach with the next() and before() functions to find the pair of elements in the BST whose sum is equal to k.

Time Complexity:
- The findTarget() function uses two pointers (one for the left and one for the right traversal of the BST) and performs a two pointer traversal of the BST, taking O(n) time, where n is the number of nodes in the BST.
- The next() and before() functions take O(h) time each, where h is the height of the BST, as they traverse the leftmost and rightmost paths in the BST.

Space Complexity:
- The space complexity is O(h), where h is the height of the BST, as the stacks store the nodes in the leftmost and rightmost paths of the BST.

*/

stack<TreeNode*> stl;
stack<TreeNode*> str;

void pushLeft(TreeNode* root) {
    while (root) {
        stl.push(root);
        root = root->left;
    }
}

void pushRight(TreeNode* root) {
    while (root) {
        str.push(root);
        root = root->right;
    }
}

int next() {
    if (stl.empty()) return 1e9;
    TreeNode* ans = stl.top();
    stl.pop();
    if (ans->right) {
        pushLeft(ans->right);
    }
    return ans->val;
}

int before() {
    if (str.empty()) return 1e9;
    TreeNode* ans = str.top();
    str.pop();
    if (ans->left) {
        pushRight(ans->left);
    }
    return ans->val;
}

bool findTarget(TreeNode* root, int k) {
    pushLeft(root);
    pushRight(root);

    int l = next();
    int r = before();
    while (l < r) {
        if (l == 1e9 || r == 1e9) return false;
        if (l + r == k) return true;
        else if (l + r < k) l = next();
        else r = before();
    }

    return false;
}
