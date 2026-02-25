/*
QUESTION:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

Return true if you can finish all courses. Otherwise, return false.

APPROACH:
- We can model the problem as a directed graph, where each course is a node, and a prerequisite pair [ai, bi] indicates a directed edge from course bi to course ai.
- To check if we can finish all courses, we need to ensure that the directed graph is a DAG (Directed Acyclic Graph) with no cycles.
- If there are cycles in the graph, it means there is a circular dependency between courses, and we cannot finish all courses in such cases.
- To check for cycles, we can use Kahn's algorithm for Topological Sorting.
- If we can perform a successful Topological Sort (i.e., there is no cycle), then it means we can finish all courses.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N + E), where N is the number of courses (nodes) and E is the number of prerequisites (edges) in the graph. We perform a BFS-like traversal of all nodes and edges.
- Space Complexity: O(N + E), where N is the number of courses (nodes) and E is the number of prerequisites (edges) in the graph. We use additional space to store the adjacency list and indegree of each node.
*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indeg(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    // Calculate the indegree of each course and build the adjacency list
    for (auto it : prerequisites) {
        indeg[it[0]]++;
        adj[it[1]].push_back(it[0]);
    }

    queue<int> q;

    // Find courses with indegree 0 and add them to the queue
    for (int i = 0; i < numCourses; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        // Remove the course and its outgoing edges
        for (auto v : adj[node]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // If the count of finished courses is equal to the total number of courses, return true
    return cnt == numCourses;
}
