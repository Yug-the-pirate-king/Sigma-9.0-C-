/**Question:**

Write a program to print the path from the root to a given node in a binary tree. You are given a binary tree and a node value. You need to find and print the path from the root to the node.

**Approach:**

To find the path from the root to the given node, we can use a recursive function. The idea is to traverse the tree from the root and keep track of the path in a vector. If the target node is found, add the node's value to the path vector, and return true. Otherwise, recursively search for the target node in the left and right subtrees. If the target node is not found, remove the last node from the path vector before returning false.

**Complexity Analysis:**

Let N be the number of nodes in the binary tree.

- Time Complexity: The time complexity of the recursive function is O(N) as we may visit all nodes in the worst case.
- Space Complexity: The space complexity is O(N) due to the space used by the recursion stack and the path vector.

**Code:**/

bool findPath(TreeNode* root, int target, vector<int>& path) {
    if (!root) return false;

    path.push_back(root->val);

    if (root->val == target) {
        return true;
    }

    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

vector<int> getPathFromRootToNode(TreeNode* root, int target) {
    vector<int> path;
    findPath(root, target, path);
    return path;
}


