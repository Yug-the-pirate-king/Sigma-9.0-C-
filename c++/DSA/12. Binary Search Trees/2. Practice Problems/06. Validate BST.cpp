/*
Question:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

Example:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Approach:
- Initialize the range with LONG_MIN and LONG_MAX values.
- Now, if a node->val is out of the range then it's not a BST
- And, then check for the left and right subtrees with modified range 

Time Complexity: O(n)
- The in-order traversal visits each node exactly once, where n is the number of nodes in the binary tree.

Space Complexity: O(h)
- The space complexity is determined by the recursion stack during the in-order traversal, where h is the height of the binary tree.
- In the worst case, the height of the binary tree can be n for a skewed tree, so the space complexity becomes O(n).
- However, for a balanced BST, the height is log n, so the space complexity becomes O(log n).

*/

bool solve(TreeNode* root, long low, long high){
    if(!root) return true;
    if(root->val >= high || root->val <= low) return false;
    return solve(root->left,low,(long)root->val) && solve(root->right,(long)root->val,high); 
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    return solve(root,LONG_MIN,LONG_MAX);
}
