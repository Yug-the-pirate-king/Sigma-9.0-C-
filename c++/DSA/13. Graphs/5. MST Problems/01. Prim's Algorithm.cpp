/* QUESTION:

Given a weighted, undirected and connected graph of V vertices and E edges, the task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Example:

Input: 
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.

APPROACH:
- We will use Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
- The idea is to start from any vertex (let's say vertex 0) and add it to the MST.
- Then, we will add the edges connected to vertex 0 to a priority queue (min-heap), where the edges are sorted based on their weights in ascending order.
- We will keep adding the edges with the minimum weight to the MST and add their connected vertices to the priority queue if they are not already in the MST.
- We will repeat this process until all vertices are added to the MST.

COMPLEXITY ANALYSIS:
- The time complexity of Prim's algorithm is O(V^2) using an adjacency matrix representation, where V is the number of vertices.
- If an adjacency list representation is used, the time complexity reduces to O(E + V log V), where E is the number of edges and log V is the time complexity of priority queue operations.
- The space complexity is O(V) for the priority queue and other data structures.

CODE:
*/

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<pair<int, int>> adj[n];
    for (auto e : edges) {
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }

    vector<bool> mst(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int ans = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        int u = node.second, uwt = node.first;
        pq.pop();

        if (!mst[u]) {
            mst[u] = true;
            ans += uwt;

            for (auto vec : adj[u]) {
                int v = vec.second, vwt = vec.first;
                if (!mst[v])
                    pq.push({vwt, v});
            }
        }
    }

    return ans;
}
