// QUESTION:
// Given a Binary Search Tree (BST) with `n` number of nodes and a value `x`, find the greatest value node of the BST which is smaller than or equal to `x`.
// Note: If `x` is smaller than the smallest node of the BST, then return -1.

// APPROACH:
// To find the floor of `x` in the BST, we can perform a recursive traversal of the tree starting from the root. While traversing, we compare the value of the current node with `x` to find the largest value in the tree that is smaller than or equal to `x`. We update the `ans` variable with the current node's value if it is smaller than or equal to `x` and continue the traversal in the left or right subtree.

// Complexity Analysis
// Time complexity: O(h), where h is the height of the BST. In the worst case, the function needs to traverse the entire height of the BST.
// Space complexity: O(1), as the function uses a single integer variable (`ans`) to store the result.

// CODE:-

int findFloor(Node* root, int x) {
    if (!root) return -1;
    int ans = -1;
    while (root) {
        if (root->data == x) {
            ans = root->data;
            break;
        } else if (root->data < x) {
            ans = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}


