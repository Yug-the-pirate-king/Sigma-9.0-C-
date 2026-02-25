/* QUESTION:

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

APPROACH:
- We can use Dijkstra's algorithm to find the minimum time it takes for all the nodes to receive the signal.
- We will create an adjacency list to represent the graph, where each node will have a list of neighboring nodes with their corresponding signal travel time.
- We will use a priority queue to perform Dijkstra's algorithm starting from the given node k.
- During Dijkstra's algorithm, we will keep track of the minimum time to reach each node from the given node k.
- Continue the algorithm until we have explored all nodes in the graph.
- Return the maximum time among all the nodes' signal travel times, as this represents the minimum time it takes for all the nodes to receive the signal.

COMPLEXITY ANALYSIS:
- The time complexity of Dijkstra's algorithm is O(E*log(V)), where E is the number of edges and V is the number of vertices.
- The space complexity is O(V) to store the distance values.

CODE:
*/

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n + 1];
    for (auto time : times) {
        adj[time[0]].push_back({time[1], time[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 1e9);
    dis[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [uwt, u] = pq.top();
        pq.pop();
        for (auto [v, vwt] : adj[u]) {
            if (dis[v] > uwt + vwt) {
                dis[v] = uwt + vwt;
                pq.push({dis[v], v});
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 1e9)
            return -1;
        ans = max(ans, dis[i]);
    }
    return ans;
}
