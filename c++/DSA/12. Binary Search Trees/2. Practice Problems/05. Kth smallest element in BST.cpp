/*
Question:
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Approach:
To find the kth smallest value in a binary search tree (BST), we can perform an in-order traversal of the BST and keep track of the count of nodes visited so far. When the count becomes equal to k, we have found the kth smallest value.

1. Perform in-order traversal of the BST.
2. While traversing, keep track of the count of nodes visited and compare it with k.
3. When count becomes equal to k, store the value of the current node as the answer.

Example:
Consider the BST [3, 1, 4, null, 2].

          3
         / \
        1   4
         \
          2

In-order traversal of this BST gives: 1, 2, 3, 4. The 1st smallest value is 1, 2nd smallest value is 2, 3rd smallest value is 3, and so on.

Time Complexity: O(log n + k)
- The in-order traversal of a balanced BST takes O(log n) time on average.
- Finding the kth smallest value takes O(k) time in the worst case when k is close to n (the number of nodes in the BST).
- In the worst case, the total time complexity becomes O(log n + k).

Space Complexity: O(log n)
- The space complexity is determined by the recursion stack during the in-order traversal, which has a maximum depth of log n for a balanced BST.

CODE:-

*/

void inorder(TreeNode* root, int k, int& cnt, int& ans) {
    if (!root) return;
    inorder(root->left, k, cnt, ans);
    cnt++;
    if (cnt == k) {
        ans = root->val;
        return;
    }
    inorder(root->right, k, cnt, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1, cnt = 0;
    inorder(root, k, cnt, ans);
    return ans;
}
