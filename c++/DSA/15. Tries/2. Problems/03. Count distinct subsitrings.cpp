/*
QUESTION:
Given a string of length N of lowercase alphabet characters. Implement the function countDistinctSubstring() to return the count of total distinct substrings of the given string.

Approach:
- Create a Trie data structure to efficiently store and count distinct substrings.
- For each character in the string, insert its suffixes into the Trie, and each insertion increases the count of distinct substrings.
- Return the total count of distinct substrings.

Complexity Analysis:
- Inserting each substring into the Trie takes O(N) time and O(N) space.
- Overall time complexity is O(N^2) since there are O(N^2) substrings in total.
- Space complexity is O(N) to store the Trie.
*/

class TrieNode {
public:
    TrieNode* child[26];
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
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
    
    void insert(string word, int& cnt) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int ltr = word[i] - 'a';
            if (!curr->child[ltr]) {
                cnt++;
                curr->child[ltr] = new TrieNode();
            }
            curr = curr->child[ltr];
        }
    }
};

int countDistinctSubstring(string s) {
    int cnt = 0;
    Trie* tr = new Trie();
    for (int i = 0; i < s.size(); i++) {
        tr->insert(s.substr(i), cnt);
    }
    return cnt + 1; // Adding 1 for the empty string itself
}
