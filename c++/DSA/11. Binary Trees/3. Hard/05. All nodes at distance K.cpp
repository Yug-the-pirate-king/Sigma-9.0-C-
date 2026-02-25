/* QUESTION:

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


APPROACH:

To find the nodes that are at a distance k from the target node, we can perform a two-step process:
1. First, traverse the binary tree to build a map of each node to its parent node using BFS. This map will help us later to backtrack from the target node to its ancestors.
2. Next, perform a BFS from the target node to find all nodes at a distance k from it. While doing this, we also mark visited nodes to avoid revisiting the same nodes.

COMPLEXITY ANALYSIS:

Let `n` be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we need to traverse the entire binary tree to build the parent map and perform BFS from the target node.
- Space Complexity: The space complexity is O(n) for the parent map and O(k) for the queue used in BFS. In the worst case, when k approaches n, the space complexity becomes O(n).

CODE:
*/

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    unordered_map<int, TreeNode*> parent;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int si = q.size();
        for (int i = 0; i < si; i++) {
            auto top = q.front();
            q.pop();

            if (top->left) {
                parent[top->left->val] = top;
                q.push(top->left);
            }

            if (top->right) {
                parent[top->right->val] = top;
                q.push(top->right);
            }
        }
    }

    unordered_map<int, int> visited;
    q.push(target);
    while (k-- && !q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto top = q.front();
            q.pop();

            visited[top->val] = 1;

            if (top->left && !visited[top->left->val]) {
                q.push(top->left);
            }

            if (top->right && !visited[top->right->val]) {
                q.push(top->right);
            }

            if (parent[top->val] && !visited[parent[top->val]->val]) {
                q.push(parent[top->val]);
            }
        }
    }

    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
