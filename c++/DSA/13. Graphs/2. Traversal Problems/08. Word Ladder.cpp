/*
QUESTION:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
1. Every adjacent pair of words differs by a single letter.
2. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
3. sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

APPROACH:
- We can model this problem as a graph where each word is a node and there is an edge between two words if they differ by a single letter.
- First, we create an adjacency list to represent the graph based on the given wordList. Two words are adjacent if they differ by one character.
- Then, we use Breadth-First Search (BFS) to find the shortest transformation sequence from beginWord to endWord.
- We start BFS from the beginWord and traverse the graph level by level, marking visited words to avoid revisiting them.
- During the BFS, if we reach the endWord, we return the length of the transformation sequence.

COMPLEXITY ANALYSIS:
- Time Complexity: O(n^2 * m), where n is the size of wordList and m is the average length of the words in wordList. In the worst case, we may need to compare every pair of words in wordList to create the adjacency list.
- Space Complexity: O(n^2), where n is the size of wordList. We use additional space for the adjacency list and the visited map.
*/

bool isAdj(string& a, string& b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            if(cnt > 0) return false;
            cnt++;
        }
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> adj;
    wordList.push_back(beginWord);
    int n = wordList.size();
    
    // Create the adjacency list
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && isAdj(wordList[i], wordList[j])){
                adj[wordList[i]].push_back(wordList[j]);
            }
        }
    }
    
    queue<string> q;
    unordered_map<string, bool> vis;
    q.push(beginWord);
    vis[beginWord] = true;
    int lvl = 1;
    
    // Perform BFS
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            string node = q.front();
            q.pop();
            if(node == endWord) return lvl;
            for(auto s : adj[node]){
                if(!vis[s]){
                    vis[s] = true;
                    q.push(s);
                }
            }
        }
        lvl++;
    }
    
    return 0;
}
