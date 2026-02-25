/*
Question:
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Explanation:
- We perform an in-order traversal of the BST to find the two nodes that are swapped.
- During the in-order traversal, we keep track of the previous node and compare it with the current node. If the current node is less than the previous node, then we have found the two swapped nodes.
- We swap the values of the two nodes to recover the BST.

Time Complexity:
- The in-order traversal takes O(n) time, where n is the number of nodes in the BST.

Space Complexity:
- The space complexity is O(h), where h is the height of the BST, as the recursion stack stores the nodes in the leftmost path of the BST.

*/

TreeNode* prev = NULL;
TreeNode* first = NULL;
TreeNode* last = NULL;

void traversal(TreeNode* root) {
    if (!root) return;
    traversal(root->left);
    if (prev && root->val < prev->val) {
        if (!first)
            first = prev;
        last = root;
    }
    prev = root;
    traversal(root->right);
}

void recoverTree(TreeNode* root) {
    if (!root) return;
    traversal(root);
    int temp = first->val;
    first->val = last->val;
    last->val = temp;
}
