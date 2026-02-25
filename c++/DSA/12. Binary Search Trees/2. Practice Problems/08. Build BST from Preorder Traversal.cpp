/*
Question:
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Approach:
- The first element of the preorder traversal is the root of the BST.
- We start with the first element of the preorder traversal and recursively build the BST as follows:
    - If the current element is greater than the previous element, it must be the right child of the previous element. We build the right subtree of the previous element using this information and recursively move forward in the preorder array.
    - If the current element is smaller than the previous element, it must be a left child of one of the previous elements. We keep on traversing the preorder array until we find an element greater than the current element. This element will be the right child of one of the ancestors of the current element.

Time Complexity: O(n)
- In the worst case, we might need to traverse the entire preorder array to construct the BST.

Space Complexity: O(h)
- The space complexity is determined by the recursion stack during the function call.
- In the worst case, the height of the BST can be n for a skewed tree, so the space complexity becomes O(n).
- However, for a balanced BST, the height is log n, so the space complexity becomes O(log n).
*/

TreeNode* solve(int& index, vector<int>& pre, int bound) {
    if (index >= pre.size() || pre[index] > bound) {
        return NULL;
    }
    TreeNode* root = new TreeNode(pre[index++]);
    root->left = solve(index, pre, root->val);
    root->right = solve(index, pre, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return solve(i, preorder, INT_MAX);
}
