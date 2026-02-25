/*
QUESTION:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

APPROACH:
- We can use Topological Sorting to check if a directed graph contains a cycle or not.
- If a directed graph is a DAG (Directed Acyclic Graph), it means it does not contain any cycle.
- So, to check for a cycle, we perform a variation of Topological Sorting using Kahn's algorithm, which is based on the concept of indegree.
- If there is no cycle in the graph, we can always find a node with an indegree of 0 (no incoming edges) and remove it along with its outgoing edges.
- We keep repeating this process, and if at any point we are unable to find a node with an indegree of 0, it means there is a cycle in the graph.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. We perform a BFS-like traversal of all nodes and edges.
- Space Complexity: O(V), where V is the number of vertices (nodes) in the graph. We use additional space to store the indegree of each node and the queue for BFS.
*/

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indeg(V, 0);

    // Calculate the indegree of each node
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indeg[it]++;
        }
    }

    queue<int> q;

    // Find nodes with indegree 0 and add them to the queue
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        // Remove the node and its outgoing edges
        for (auto i : adj[node]) {
            indeg[i]--;
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
    }

    // If the count of removed nodes is not equal to the total number of nodes, there is a cycle
    return !(cnt == V);
}
