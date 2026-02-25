/* QUESTION:

Given the root of a complete binary tree, return the number of nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.


APPROACH:

To count the number of nodes in the complete binary tree efficiently, we can make use of the property of complete binary trees. Since all levels of the tree, except possibly the last level, are completely filled, we can perform binary search on the last level to find the number of nodes.

1. First, we calculate the height of the left and right subtrees starting from the root.
2. If the height of the left subtree is equal to the height of the right subtree, it means that the last level is completely filled, and the number of nodes in the tree is 2^h - 1, where h is the height of the tree.
3. If the heights are not equal, it means that the last level is not completely filled. In this case, we recursively calculate the number of nodes in the left and right subtrees and add 1 (for the root node) to get the total number of nodes in the tree.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the complete binary tree.
- Time Complexity: The time complexity of this approach is O(log^2 n), as we perform binary search on the last level, and at each step, we calculate the height of the left and right subtrees, which takes O(log n) time. We do this operation recursively, so the overall time complexity is O(log^2 n).
- Space Complexity: The space complexity is O(log n) due to the recursion stack, where n is the height of the complete binary tree.

CODE:
*/

int leftHeight(TreeNode* root) {
    int h = 1;
    while (root) {
        h++;
        root = root->left;
    }
    return h;
}

int rightHeight(TreeNode* root) {
    int h = 1;
    while (root) {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = leftHeight(root->left);
    int rh = rightHeight(root->right);
    if (lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
