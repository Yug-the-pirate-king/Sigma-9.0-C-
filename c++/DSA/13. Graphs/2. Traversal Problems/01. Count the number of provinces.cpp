/*
Question:
Given an n x n matrix 'isConnected' representing connections between cities (nodes), find the total number of provinces in the graph.

Explanation:
- The problem can be solved using Depth First Search (DFS).
- We first convert the given matrix 'isConnected' into an adjacency list 'adj' representing the graph.
- We use a 'vis' vector to keep track of visited cities, initialized to 'false' for all cities.
- We initialize a variable 'ans' to store the number of provinces.
- We then perform DFS from each city and mark all directly or indirectly connected cities as visited.
- We increment the 'ans' for each unvisited city and continue the process until all cities are visited.
- Finally, we return the 'ans' which represents the total number of provinces in the graph.

Time Complexity:
- The time complexity is O(n^2), where n is the number of cities. We traverse the entire 'isConnected' matrix to construct the adjacency list.

Space Complexity:
- The space complexity is O(n), where n is the number of cities. We use extra space for the adjacency list and the 'vis' vector.

*/

void dfs(int node, vector<int> adj[], vector<bool>& vis){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v])
            dfs(v, adj, vis);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int ans = 0, n = isConnected.size();
    vector<int> adj[n];
    
    // Convert isConnected matrix into adjacency list
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    
    vector<bool> vis(n, false);
    
    // Perform DFS to find the number of provinces
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans++;
            dfs(i, adj, vis);
        }
    }

    return ans;
}
