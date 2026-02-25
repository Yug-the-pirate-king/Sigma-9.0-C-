/*
QUESTION:
Ninja has to implement a data structure "TRIE" from scratch. Implement the functions as follows:
1) Trie(): Initializes the trie object.
2) insert("WORD"): Inserts the string "WORD" into the trie.
3) countWordsEqualTo("WORD"): Returns how many times the string "WORD" is present in the trie.
4) countWordsStartingWith("PREFIX"): Returns how many words in the trie have the string "PREFIX" as a prefix.
5) erase("WORD"): Deletes one occurrence of the string "WORD" from the trie.

Approach:
- Create a TrieNode class with an array of child nodes, each representing a letter.
- Maintain the count of words with a specific prefix (cntPre) and the count of words (cntWord) at each node.
- Implement insert, countWordsEqualTo, countWordsStartingWith, and erase functions using TrieNode operations.

Complexity Analysis:
- All operations take O(L) time, where L is the length of the word or prefix.
- Space complexity is O(N * M), where N is the number of words and M is the average length of the words.
*/

class TrieNode {
public:
    int cntWord, cntPre;
    TrieNode* child[26];
    
    TrieNode() {
        this->cntPre = 0;
        this->cntWord = 0;
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

    void insert(string &word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int ltr = word[i] - 'a';
            if (!curr->child[ltr])
                curr->child[ltr] = new TrieNode();
            curr = curr->child[ltr];
            curr->cntPre++;
        }
        curr->cntWord++;
    }

    int countWordsEqualTo(string &word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int ltr = word[i] - 'a';
            if (!curr->child[ltr])
                return 0;
            curr = curr->child[ltr];
        }
        return curr->cntWord;
    }

    int countWordsStartingWith(string &prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            int ltr = prefix[i] - 'a';
            if (!curr->child[ltr])
                return 0;
            curr = curr->child[ltr];
        }
        return curr->cntPre;
    }

    void erase(string &word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int ltr = word[i] - 'a';
            curr = curr->child[ltr];
            curr->cntPre--;
        }
        curr->cntWord--;
    }
};

