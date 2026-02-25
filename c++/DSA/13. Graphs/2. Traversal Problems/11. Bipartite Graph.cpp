/*
QUESTION:
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
1. There are no self-edges (graph[u] does not contain u).
2. There are no parallel edges (graph[u] does not contain duplicate values).
3. If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

APPROACH:
- We can use Depth-First Search (DFS) to color the nodes in the graph such that we can partition them into two sets A and B.
- While performing the DFS, we use two colors: 1 and -1 to color the nodes. We start by coloring the first node with color 1.
- For each uncolored node, we perform DFS and color its neighbors with the opposite color.
- If we encounter a neighbor with the same color as the current node, the graph is not bipartite, and we return false.
- If the DFS completes without any conflicts, we return true, indicating that the graph is bipartite.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of nodes (vertices) in the graph, and E is the number of edges in the graph. We visit each node and each edge exactly once during the DFS.
- Space Complexity: O(V), where V is the number of nodes (vertices) in the graph. We use additional space to store the colors of the nodes.
*/

bool dfs(int node, int color, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = color;
    for(auto v : adj[node]){
        if(!vis[v] && !dfs(v, -color, adj, vis)){
            return false;
        }
        if(vis[v] == color){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n);
    for(int i = 0; i < n; i++){
        if(!vis[i] && !dfs(i, 1, graph, vis)){
            return false;
        }
    }
    return true;
}
