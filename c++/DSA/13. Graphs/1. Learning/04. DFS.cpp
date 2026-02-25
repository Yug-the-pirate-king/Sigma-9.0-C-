/*
Question:
Given a connected undirected graph, perform Depth First Traversal (DFS) of the graph starting from vertex 0 and visit all the nodes directly or indirectly connected to Node 0.

Explanation:
- We initialize an empty vector 'ans' to store the DFS traversal.
- We also initialize a vector 'vis' to keep track of visited nodes, initialized with 'false' for all nodes.
- We start DFS from vertex 0 by calling the recursive function 'dfs'.
- In the 'dfs' function, we push the current node into the 'ans' vector and mark it as visited.
- For each adjacent vertex of the current node, if it has not been visited, we call the 'dfs' function recursively for that vertex.
- We continue this process until all connected nodes are visited.
- Finally, we return the 'ans' vector containing the DFS traversal.

Time Complexity:
- The time complexity is O(V + E), where V is the number of vertices and E is the number of edges in the graph. In the worst case, we visit all the vertices and edges.

Space Complexity:
- The space complexity is O(V), where V is the number of vertices, as we use extra space for the 'vis' vector.

*/

void dfs(int node, vector<int> adj[], vector<int>& ans, vector<bool>& vis){
    ans.push_back(node);
    vis[node] = true;
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(i, adj, ans, vis);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V, false);
    dfs(0, adj, ans, vis);
    return ans;
}
