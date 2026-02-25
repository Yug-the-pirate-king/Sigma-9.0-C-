/* QUESTION:

Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.

Example:

Input: E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]], S = 2
Output: 1 6 0
Explanation:
For nodes 2 to 0, we can follow the path - 2 -> 0. This has a distance of 1.
For nodes 2 to 1, we can follow the path - 2 -> 0 -> 1, which has a distance of 1 + 5 = 6.

APPROACH:
- We can use Bellman-Ford algorithm to find the shortest distance of all the nodes from the given source vertex S.
- The Bellman-Ford algorithm can handle negative edge weights and identify negative cycles.
- We will initialize an array dis to store the shortest distance of each node from the source vertex. Initialize all distances to a very large value except for the source vertex, which will have a distance of 0.
- Run a loop for V-1 times (V is the number of vertices), and in each iteration, relax all the edges to minimize the distance.
- If there is a negative cycle, the distance will keep decreasing in the Vth iteration as well. In this case, we will return an array containing only -1.
- Otherwise, we return the dis array with the shortest distances of all nodes from the source vertex.

COMPLEXITY ANALYSIS:
- The time complexity of the Bellman-Ford algorithm is O(V*E), where V is the number of vertices and E is the number of edges.
- The space complexity is O(V) to store the distance values.

CODE:
*/


vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<pair<int, int>> adj[V];
    for (auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
    }
    vector<int> dis(V, 1e8);
    dis[S] = 0;
    for (int i = 0; i < V; i++) {
        for (int u = 0; u < V; u++) {
            for (auto vec : adj[u]) {
                int v = vec.first, wt = vec.second;
                if (dis[u] != 1e8)
                    dis[v] = min(dis[v], dis[u] + wt);
            }
        }
    }
    for (int u = 0; u < V; u++) {
        for (auto vec : adj[u]) {
            int v = vec.first, wt = vec.second;
            if (dis[u] != 1e8 && dis[v] > dis[u] + wt)
                return {-1};
        }
    }
    return dis;
}
