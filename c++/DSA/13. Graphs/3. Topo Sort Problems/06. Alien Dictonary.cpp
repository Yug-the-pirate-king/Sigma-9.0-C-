/*
QUESTION:
Given a sorted dictionary of an alien language having N words and k starting alphabets of the standard dictionary. Find the order of characters in the alien language.

APPROACH:
- We are given a sorted dictionary of an alien language.
- To find the order of characters in the alien language, we can use a directed graph approach along with topological sorting.
- We create a directed graph where each node represents a character, and there is a directed edge from node 'a' to node 'b' if character 'a' comes before character 'b' in the alien language.
- We also keep track of the indegree of each node, which represents the number of characters that come before it in the alien language.
- We iterate through the dictionary and set the directed edges and indegrees accordingly.
- We then start with the nodes having an indegree of 0 (i.e., the characters that come first in the alien language) and perform a BFS-like traversal.
- During the traversal, we keep reducing the indegree of the nodes that come after the current node.
- The characters that become terminal nodes (i.e., their indegree becomes 0) during the traversal are the characters that come last in the alien language.
- We construct the order of characters based on the BFS traversal, and that will be the correct order of characters in the alien language.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N), where N is the number of words in the dictionary. We iterate through the dictionary once to set the directed edges and indegrees.
- Space Complexity: O(K), where K is the number of starting alphabets in the standard dictionary. We use additional space to store the directed graph and indegrees.
*/

void setAdj(string a, string b, vector<int> adj[], vector<int>& indeg){
    int as = a.size(), bs = b.size();
    int n = min(as,bs);
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            adj[a[i]-'a'].push_back(b[i]-'a');
            indeg[b[i]-'a']++;
            break;
        }
    }
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    vector<int> indeg(K);

    // Set the directed edges and indegrees
    for(int i=1; i<N; i++){
        setAdj(dict[i-1],dict[i],adj,indeg);
    }

    queue<int> q;
    for(int i=0; i<K; i++){
        if(indeg[i]==0){
            q.push(i);
        } 
    }

    string ans = "";
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            int node = q.front();
            q.pop();
            ans += node+'a';
            for(auto v:adj[node]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }
    }

    return ans; 
}
