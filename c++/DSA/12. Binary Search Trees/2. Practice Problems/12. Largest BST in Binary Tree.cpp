/*
Question:
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Explanation:
- We use a recursive function to traverse the binary tree in a bottom-up manner.
- At each node, we check if the left and right subtrees are binary search trees.
- If the current node satisfies the binary search tree condition (i.e., the value of the current node is greater than the maximum value in the left subtree and less than the minimum value in the right subtree), then we update the size of the largest subtree.
- We return a triplet containing the size of the subtree, the minimum value in the subtree, and the maximum value in the subtree.

Time Complexity:
- The recursive function visits each node once, so the time complexity is O(n), where n is the number of nodes in the binary tree.

Space Complexity:
- The space complexity is O(h), where h is the height of the binary tree, as the recursion stack stores the nodes in the path from the root to the deepest leaf node.

*/

typedef pair<int,pair<int,int>> triplet;

triplet solve(Node* root) {
    if (!root) return {0, {INT_MAX, INT_MIN}};
    auto lef = solve(root->left);
    auto rig = solve(root->right);
    if (lef.second.second < root->data && root->data < rig.second.first)
        return {lef.first + rig.first + 1, {min(lef.second.first, root->data), max(rig.second.second, root->data)}};
    // here we are returning such values so that it bst condition doesn't satisfy upwards
    return {max(lef.first, rig.first), {INT_MIN, INT_MAX}};
}

int largestBst(Node *root) {
    auto ans = solve(root);
    return ans.first;
}
