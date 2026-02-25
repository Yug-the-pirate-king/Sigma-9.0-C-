/* QUESTION:

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

APPROACH:

To serialize the binary tree, we can perform a preorder traversal of the tree and append the node values to a string, separating them by a delimiter.

To deserialize the string back to the original tree structure, we can use a stringstream to split the string by the delimiter and recursively build the tree.

1. For serialization:
   - If the current node is NULL, we append "N," to the string.
   - Otherwise, we append the node value followed by a delimiter "," to the string.
   - We then recursively serialize the left and right subtrees.

2. For deserialization:
   - If the current string token is "N," indicating a NULL node, we return NULL.
   - Otherwise, we convert the string token to an integer and create a new TreeNode with the value.
   - We then recursively deserialize the left and right subtrees.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity:
  - Serialization: O(n) - We visit each node once during the serialization process.
  - Deserialization: O(n) - We process each string token once during the deserialization process.
- Space Complexity: O(n) - The space required for the serialized string and the recursion stack.

CODE:
*/

void serialize(TreeNode* root, string& serialized) {
    if (!root) {
        serialized += "N,";
        return;
    }
    serialized += to_string(root->val) + ",";
    serialize(root->left, serialized);
    serialize(root->right, serialized);
}

string serialize(TreeNode* root) {
    string serialized;
    serialize(root, serialized);
    return serialized;
}

TreeNode* deserialize(stringstream& ss) {
    string token;
    getline(ss, token, ',');
    if (token == "N")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(token));
    root->left = deserialize(ss);
    root->right = deserialize(ss);
    return root;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return deserialize(ss);
}
