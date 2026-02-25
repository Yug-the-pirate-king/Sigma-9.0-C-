/*
QUESTION:-
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.

Approach:
1. We can use Tarjan's algorithm to find the critical connections in the network.
2. Tarjan's algorithm is used to find bridges in an undirected graph, which are exactly the critical connections.
3. We perform a depth-first search (DFS) on the graph and keep track of the timestamp (time) when each node is visited.
4. We also maintain two arrays, tin and low, to store the timestamp of each node and the lowest timestamp reachable from the node using a back edge or a cross edge, respectively.
5. During the DFS, if we encounter an edge (u, v) such that low[v] > tin[u], it means the edge (u, v) is a critical connection (bridge).
6. We add all such critical connections to the result.

Complexity Analysis:
- Let n be the number of servers and m be the number of connections in the network.
- The time complexity of this approach is O(n + m) since we perform a single DFS on the graph.
- The space complexity is O(n + m) to store the graph adjacency list and O(n) for the auxiliary arrays.
*/


int time;

void dfs(int node, int parent, int tin[], int low[], vector<int> adj[], vector<vector<int>>& ans, vector<bool>& vis) {
    vis[node] = true;
    low[node] = tin[node] = time;
    time++;

    for (auto v : adj[node]) {
        if (v == parent) continue;
        if (vis[v]) {
            low[node] = min(low[node], low[v]);
        } else {
            dfs(v, node, tin, low, adj, ans, vis);
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node])
                ans.push_back({v, node});
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    time = 0;
    vector<int> adj[n];
    for (auto c : connections) {
        adj[c[0]].push_back(c[1]);
        adj[c[1]].push_back(c[0]);
    }
    vector<vector<int>> ans;
    vector<bool> vis(n);
    int tin[n], low[n];
    dfs(0, -1, tin, low, adj, ans, vis);
    return ans;
}
