/* QUESTION:

The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph.
The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j.
If Matrix[i][j] = -1, it means there is no edge from i to j.

Example:

Input: matrix = {{0, 25}, {-1, 0}}

Output: {{0, 25}, {-1, 0}}

Explanation: The shortest distance between every pair is already given (if it exists).

APPROACH:
- We will first replace all the "-1" entries in the adjacency matrix with a very large value (e.g., 1e9) to represent that there is no edge between those vertices.
- Then, we will apply the Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices in the graph.
- In each iteration, we will consider an intermediate vertex k and update the shortest distance between each pair (i, j) if the path i -> k -> j is shorter than the current distance i -> j.
- After completing the algorithm, we will replace the entries with a very large value (e.g., 1e9) with -1 in the adjacency matrix to represent that there is no path between those vertices.

COMPLEXITY ANALYSIS:
- The time complexity of the Floyd-Warshall algorithm is O(V^3), where V is the number of vertices.
- The space complexity is O(1) since we are modifying the input matrix in-place.

CODE:
*/

void shortest_distance(vector<vector<int>>& matrix) {
    int v = matrix.size();

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
        }
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (i == j)
                    matrix[i][j] = 0;
                matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}
