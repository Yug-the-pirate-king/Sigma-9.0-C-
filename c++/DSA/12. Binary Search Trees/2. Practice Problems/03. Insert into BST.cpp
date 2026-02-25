/*
Question:
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
*/

/*
Approach:
1. To insert a value 'val' into the BST, we start from the root node and traverse down the tree to find the appropriate position for insertion.
2. If the BST is empty (i.e., root is null), we create a new node with value 'val' and make it the root of the BST.
3. If the value of the current node is less than 'val', we move to the right subtree, as the value to be inserted will be greater than the current node.
4. If the value of the current node is greater than or equal to 'val', we move to the left subtree, as the value to be inserted will be less than or equal to the current node.
5. We continue this process of traversing down the tree until we reach a leaf node where we can insert the new value 'val'.

Complexity Analysis
Time complexity: O(h), where h is the height of the BST. In the worst case, the function needs to traverse the entire height of the BST to find the appropriate position for insertion.
Space complexity: O(h), where h is the height of the BST. In the worst case, the function may have to traverse the entire height of the BST, leading to h recursive calls in the call stack.

CODE:-

*/

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val < val) root->right = insertIntoBST(root->right, val); 
    else root->left =  insertIntoBST(root->left, val);
    return root;
}
