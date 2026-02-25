/*
QUESTION:
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Approach:
1. Create a Trie data structure that stores binary representations of the given numbers.
2. For each number, insert its binary representation into the Trie.
3. For each number, find the maximum XOR that can be obtained with any other number using the Trie.
   - Traverse the Trie for each bit of the number and try to find a bit in the other number's binary representation that gives the maximum XOR.
   - If a complementary bit is found, set the corresponding bit in the result.
4. Return the maximum XOR found.

Complexity Analysis:
- The Trie insertion and search operations both take O(32) time since we are dealing with 32 bits (maximum). Therefore, the time complexity of the solution is O(n * 32), which simplifies to O(n).
- The space complexity is also O(n) since we are storing the Trie.

CODE:
*/

class TrieNode {
public:
    TrieNode* child[2];
    
    TrieNode() {
        for(int i = 0; i < 2; i++) {
            this->child[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* curr = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }
    
    int findMax(int num) {
        TrieNode* curr = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(curr->child[1 - bit]) {
                maxNum = maxNum | (1 << i);
                curr = curr->child[1 - bit];
            } else {
                curr = curr->child[bit];
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* tr = new Trie();
        for(auto i : nums) {
            tr->insert(i);
        }
        int ans = 0;
        for(auto i : nums) {
            int temp = tr->findMax(i);
            ans = max(ans, temp);
        }
        return ans;
    }
};

