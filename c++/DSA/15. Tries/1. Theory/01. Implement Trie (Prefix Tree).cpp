/*
QUESTION:
Implement the Trie class, which supports insertion, search, and startsWith operations.

Approach:
- Create a TrieNode class with an array of child nodes, each representing a letter.
- The Trie class maintains a root TrieNode.
- For insertion, traverse the trie, creating new nodes as necessary for each character.
- For search, traverse the trie, checking if nodes exist for each character and if the final node is marked as a complete word.
- For startsWith, traverse the trie similarly to search, but don't require the final node to be marked as a complete word.

Complexity Analysis:
- Insertion, search, and startsWith operations take O(L) time, where L is the length of the word or prefix.
- Space complexity is O(N * M), where N is the number of words and M is the average length of the words.

CODE:-
*/

class TrieNode{
public:
    TrieNode* child[26];
    bool isWord;

    TrieNode(){
        this->isWord = false;
        for(int i=0; i<26; i++){
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
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int ltr = word[i] - 'a';
            if(!curr->child[ltr])
                curr->child[ltr] = new TrieNode();
            curr = curr->child[ltr];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int ltr = word[i]-'a';
            if(!curr->child[ltr]) return false;
            curr = curr->child[ltr];
        }
        return curr && curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.size(); i++){
            int ltr = prefix[i]-'a';
            if(!curr->child[ltr]) return false;
            curr = curr->child[ltr];
        }
        return curr;
    }
};