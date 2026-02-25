/*
QUESTION:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

APPROACH:
- We can model the problem as a directed graph, where each course is a node, and a prerequisite pair [ai, bi] indicates a directed edge from course bi to course ai.
- To find the course ordering, we can use Kahn's algorithm for Topological Sorting.
- If we can perform a successful Topological Sort, it means we can finish all courses, and the order in which we pop the nodes from the queue will give us the correct course order.
- If there is a cycle in the graph (i.e., it is not possible to finish all courses), the algorithm will not be able to remove all nodes with indegree 0, and we will not get a valid course ordering.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N + E), where N is the number of courses (nodes) and E is the number of prerequisites (edges) in the graph. We perform a BFS-like traversal of all nodes and edges.
- Space Complexity: O(N + E), where N is the number of courses (nodes) and E is the number of prerequisites (edges) in the graph. We use additional space to store the adjacency list and indegree of each node.
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

    vector<int> courseOrder;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        courseOrder.push_back(node);

        // Remove the course and its outgoing edges
        for (auto v : adj[node]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // If the size of the course order is equal to the total number of courses, return the order
    if (courseOrder.size() == numCourses) {
        return courseOrder;
    }

    // If not all courses are covered, return an empty array
    return {};
}
