/*
QUESTION:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

APPROACH:
- To check for cycles in a directed graph, we can use Depth-First Search (DFS) with backtracking.
- During the DFS, we maintain a visited array to keep track of nodes that have been visited.
- We perform DFS from each unvisited node to explore the graph and check for cycles.
- If we encounter a node that is already visited in the current DFS traversal, it means we have found a cycle, and we return true.
- If we complete the DFS for all nodes without finding any cycle, we return false.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. We visit each node and each edge exactly once during the DFS.
- Space Complexity: O(V), where V is the number of vertices (nodes) in the graph. We use additional space to store the visited status of the nodes.
*/

bool dfs(int node, vector<int> adj[], vector<bool>& vis){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v] && dfs(v, adj, vis)){
            return true;
        }
        else if(vis[v]){
            return true;
        }
    }
    vis[node] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
    vector<int> adj[v];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<bool> vis(v);
    for(int i = 0; i < v; i++){
        if(!vis[i] && dfs(i, adj, vis)){
            return true;
        }
    }
    return false;
}
