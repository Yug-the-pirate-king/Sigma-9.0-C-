/*
Question:
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.

int next() Moves the pointer to the right, then returns the number at the pointer.

Approach:
- We are using a stack to keep track of the nodes during the in-order traversal of the BST.
- In the constructor, we initialize the stack by pushing all the leftmost nodes in the BST to the stack.
- The next() function returns the top element of the stack (which will be the next smallest element in the BST) and pops it from the stack.
- If the node has a right child, we push all the leftmost nodes in the right subtree to the stack before returning the node's value.
- The hasNext() function simply checks if the stack is empty or not.

Time Complexity:
- The constructor takes O(h) time, where h is the height of the BST, as it traverses the leftmost path in the BST.
- The next() and hasNext() functions take O(1) time as they only perform stack operations.

Space Complexity:
- The space complexity is O(h), where h is the height of the BST, as the stack stores the nodes in the leftmost path of the BST.

*/

stack<TreeNode*> st;

BSTIterator(TreeNode* root) {
    pushLeft(root);
}

void pushLeft(TreeNode* root) {
    while (root) {
        st.push(root);
        root = root->left;
    }
}

int next() {
    TreeNode* ans = st.top();
    st.pop();
    if (ans->right) {
        pushLeft(ans->right);
    }
    return ans->val;
}

bool hasNext() {
    return (!st.empty());
}
