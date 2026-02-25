/* QUESTION:

Given the root of a binary tree, flatten the tree into a "linked list".

APPROACH:

To flatten the binary tree into a linked list, we can modify the tree in-place using a modified preorder traversal.

1. We start with the current node as the root.
2. While the current node is not NULL, we do the following:
   - If the current node has a left child, we find the rightmost node of its left subtree.
     - We make the right child of the rightmost node point to the right child of the current node.
     - We set the left child of the current node to NULL.
     - We set the right child of the current node to its left child.
   - We move to the right child of the current node.
3. We repeat this process until we have visited all the nodes in the tree.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we visit each node once.
- Space Complexity: The space complexity is O(1) since we don't use any extra space.

CODE:
*/

void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            TreeNode* temp = curr->left;
            while (temp->right)
                temp = temp->right;

            temp->right = curr->right;
            curr->left = NULL;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}
