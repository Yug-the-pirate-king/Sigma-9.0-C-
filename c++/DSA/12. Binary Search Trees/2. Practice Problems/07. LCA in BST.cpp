/*
Question:
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Approach:
- Traverse the BST from the root.
- If both the nodes p and q are smaller than the current node's value, then the LCA must be in the left subtree. So, recursively call the function on the left subtree.
- If both the nodes p and q are greater than the current node's value, then the LCA must be in the right subtree. So, recursively call the function on the right subtree.
- If the current node's value is between the values of nodes p and q, then the current node is the LCA.

Time Complexity: O(h)
- h is the height of the BST.
- In the worst case, the height of the BST can be n for a skewed tree, so the time complexity becomes O(n).
- However, for a balanced BST, the height is log n, so the time complexity becomes O(log n).

Space Complexity: O(h)
- The space complexity is determined by the recursion stack during the function call.
- In the worst case, the height of the BST can be n for a skewed tree, so the space complexity becomes O(n).
- However, for a balanced BST, the height is log n, so the space complexity becomes O(log n).
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ((p->val < root->val) && (q->val < root->val)) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if ((p->val > root->val) && (q->val > root->val)) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}
