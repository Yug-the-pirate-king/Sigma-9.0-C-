/*
QUESTION:
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

APPROACH:
- We are given a directed graph, and we need to find all the safe nodes.
- A node is safe if every possible path starting from that node leads to a terminal node (or another safe node).
- To solve this, we can use a reverse graph approach along with a topological sorting method.
- We create a reverse adjacency list, where revadj[i] contains all the nodes from which there is a directed edge to node i (i.e., nodes that have an edge towards node i).
- We also keep track of the outdegree of each node, which represents the number of outgoing edges from that node.
- We then start with nodes that have an outdegree of 0 (i.e., terminal nodes) and perform a BFS-like traversal.
- During the traversal, we keep reducing the outdegree of the nodes from which there is a directed edge to the current node.
- If a node's outdegree becomes 0 during the traversal, we add it to the queue for further processing.
- All the nodes that become terminal nodes during the traversal are safe nodes.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N + E), where N is the number of nodes, and E is the number of edges in the graph. We perform a BFS-like traversal of all nodes and edges.
- Space Complexity: O(N + E), where N is the number of nodes, and E is the number of edges in the graph. We use additional space to store the reverse adjacency list and outdegree of each node.
*/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    // Creating reverse adjacency list and outdegree array
    vector<int> revadj[n];
    vector<int> outdeg(n);
    for (int i = 0; i < n; i++) {
        outdeg[i] += graph[i].size();
        for (auto j : graph[i]) {
            revadj[j].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0) q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Reduce outdegree of the nodes from which there is a directed edge to the current node
            for (auto v : revadj[node]) {
                outdeg[v]--;
                if (outdeg[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    // Sort the safe nodes in ascending order
    sort(ans.begin(), ans.end());
    return ans;
}
