/**Question:**

Given an array `order`, which represents the inorder traversal of a binary search tree (BST), the task is to check if it's valid or not.

**Approach:**

A binary search tree is considered valid if its inorder traversal is in non-decreasing order. We can simply iterate through the `order` array and check if each element is smaller than the next element. If we find any element that is greater than or equal to the next element, the BST is not valid, and we return `false`. Otherwise, we return `true`.

**Complexity Analysis:**

Let's analyze the time and space complexity of our approach:

- Time Complexity: O(N)
  - In the worst case, we need to iterate through the entire `order` array once, where N is the number of elements in the array.

- Space Complexity: O(1)
  - We are not using any additional space that grows with the input size, so the space complexity is constant.

**Code:**/


bool isValidBST(vector<int> &order) {
    for (int i = 1; i < order.size(); i++) {
        if (order[i - 1] >= order[i]) {
            return false;
        }
    }
    return true;
}
