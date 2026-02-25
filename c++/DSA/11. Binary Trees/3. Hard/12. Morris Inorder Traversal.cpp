/* QUESTION:

Given a binary tree, find the inorder traversal of the tree without using extra space.

APPROACH:

We can achieve a non-recursive inorder traversal without using extra space by modifying the binary tree itself.

1. We start with the current node as the root.
2. While the current node is not NULL, we do the following:
   - If the current node does not have a left child, we visit the current node and move to its right child.
   - If the current node has a left child, we find the rightmost node of its left subtree.
     - If the rightmost node does not have a right child, we make the right child point to the current node and move to the left child.
     - If the rightmost node already has a right child (which points back to the current node), we reset the right child to NULL, visit the current node, and move to its right child.
3. We repeat this process until we have visited all the nodes in the tree.
4. Finally, we return the result vector containing the inorder traversal.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we visit each node once.
- Space Complexity: The space complexity is O(1) since we don't use any extra space.

CODE:
*/

vector<int> inOrder(Node* root) {
    vector<int> ans;
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* rightmost = curr->left;
            while (rightmost->right && rightmost->right != curr)
                rightmost = rightmost->right;

            if (!rightmost->right) {
                rightmost->right = curr;
                curr = curr->left;
            } else {
                ans.push_back(curr->data);
                rightmost->right = NULL;
                curr = curr->right;
            }
        }
    }

    return ans;
}
