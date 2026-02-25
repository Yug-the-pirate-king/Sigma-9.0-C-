/**QUESTION:**

Given a Binary Search Tree (BST) and a number `X`, find the Ceil of `X`. Ceil(X) is a number that is either equal to `X` or is immediately greater than `X` in the BST.

If the Ceil of `X` could not be found, return `-1`.

**Example 1:**

Input:

      5
    /   \
   1     7
    \
     2 
      \
       3
X = 3

Output: 3

Explanation: We find 3 in the BST, so the ceil of 3 is 3.

**APPROACH:**

To find the Ceil of a given number `X`, we can perform a traversal of the BST and keep track of the node with the smallest value that is greater than or equal to `X`. 
We can use a recursive function to traverse the BST while updating the answer (`ans`) whenever we find a node with a greater value than `X`. If we find an exact match for `X`, we can directly set `ans` to `X`.

**COMPLEXITY ANALYSIS:**

The time complexity of this approach is O(h), where `h` is the height of the BST. In the worst case, the height of the BST can be `N` (for a skewed tree), where `N` is the number of nodes in the BST. 
In the average case, the height is usually log(N) for a balanced BST.

The space complexity is O(1) since we are using a constant amount of extra space (variables) to store the intermediate results.

**CODE:**/


void solve(Node* root, int x, int& ans) {
    if (!root) return;
    if (root->data == x) {
        ans = root->data;
        return;
    } 
    if (root->data > x) {
        ans = root->data;
        return solve(root->left, x, ans);
    }
    return solve(root->right, x, ans);
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    solve(root, input, ans);
    return ans;
}