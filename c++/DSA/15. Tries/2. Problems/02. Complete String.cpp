/*
QUESTION:
Ninja developed a fascination for arrays and strings, so this time his teacher gave him an array of strings 'A' of size 'N'. Each element of this array is a string. A string is called a complete string if every prefix of this string is also present in the array 'A'. Ninja is challenged to find the longest complete string in the array 'A'. If there are multiple strings with the same length, return the lexicographically smallest one, and if no string exists, return "None".

Example:
N = 4
A = ["ab", "abc", "a", "bp"]
Explanation:
- Only prefix of the string "a" is "a", which is present in array 'A'. So, it is one of the possible strings.
- Prefixes of the string "ab" are "a" and "ab", both of which are present in array 'A'. So, it is one of the possible strings.
- Prefixes of the string "bp" are "b" and "bp". "b" is not present in array 'A'. So, it cannot be a valid string.
- Prefixes of the string "abc" are "a", "ab", and "abc", all of which are present in array 'A'. So, it is one of the possible strings.
- We need to find the maximum length string, so "abc" is the required string.

Approach:
- Create a Trie data structure to store the strings in the array 'A'.
- Insert all the strings into the Trie.
- Iterate through each string in array 'A':
  - Check if the string is a valid complete string using the Trie.
  - If it is valid, update the answer string based on the length and lexicographical order.

Complexity Analysis:
- Inserting each string into the Trie takes O(N*K) time and space, where N is the number of strings and K is the average length of strings.
- Validating each string takes O(K) time.
- The overall time complexity is O(N*K) and the space complexity is O(N*K), where N is the number of strings and K is the average length of strings.
*/

class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        this->end = false;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* curr = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            int key = word[i] - 'a';
            if (curr->children[key] == NULL) {
                curr->children[key] = new TrieNode();
            }
            curr = curr->children[key];
        }
        curr->end = true;
    }

    bool isvalid(string& word) {
        TrieNode* curr = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            int key = word[i] - 'a';
            if (curr->children[key] == NULL || curr->children[key]->end == false) {
                return false;
            }
            curr = curr->children[key];
        }
        return curr != NULL && curr->end;
    }
};

string completeString(int n, vector<string>& a) {

    Trie tr;

    for (auto it : a) {
        tr.insert(it);
    }

    string ans = "";

    for (auto it : a) {
        if (tr.isvalid(it)) {
            if (ans.size() < it.size())
                ans = it;
            else if (ans.size() == it.size() && it < ans)
                ans = it;
        }
    }
    if (ans.size() == 0)
        return "None";
    return ans;

}
