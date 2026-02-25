/**QUESTION:**

Given a Binary Search Tree (BST), find the minimum value in it.

Example:


    8
   / 
  5
 / \
3   6 


BST for the given input looks like the above. The minimum value in this BST is `3`.

**APPROACH:**

To find the minimum value in a BST, we can traverse the left child nodes until we reach the leftmost leaf node, which will have the minimum value.

**COMPLEXITY ANALYSIS:**

Let 'n' be the number of nodes in the BST.

- Time Complexity: The time complexity of finding the minimum value in a BST is O(h), where 'h' is the height of the BST. In the worst case, the height of a skewed BST could be 'n', but in a balanced BST, the height is log(n), making the average time complexity O(log n).
- Space Complexity: The space complexity is O(1) as we are not using any extra space.

**CODE:**/

int minVal(Node* root) {
    if (!root) return -1;
    while (root->left)
        root = root->left;
    return root->data;	
}
