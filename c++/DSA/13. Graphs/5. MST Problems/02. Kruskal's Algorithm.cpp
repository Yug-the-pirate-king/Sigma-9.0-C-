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
- We will use Kruskal's algorithm to find the Minimum Spanning Tree (MST) of the graph.
- First, we will sort all the edges in non-decreasing order based on their weights.
- Then, we will initialize a Disjoint Set data structure to keep track of connected components.
- We will start adding edges one by one from the sorted list of edges to the MST.
- Before adding an edge (u, v) to the MST, we will check if u and v belong to the same connected component using the Disjoint Set data structure. If they do not belong to the same connected component, we will add the edge to the MST and union the connected components of u and v.
- We will repeat this process until all vertices are added to the MST.

COMPLEXITY ANALYSIS:
- The time complexity of Kruskal's algorithm is O(E log E), where E is the number of edges, due to the sorting step.
- The space complexity is O(V) for the Disjoint Set data structure and other data structures.

CODE:
*/

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uP = findUParent(u), vP = findUParent(v);
        if (uP == vP)
            return;
        if (size[uP] > size[vP]) {
            parent[vP] = uP;
            size[uP] += size[vP];
        } else {
            parent[uP] = vP;
            size[vP] += size[uP];
        }
    }
};

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    DisjointSet djs(n);
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto e : edges) {
        int wt = e[0], u = e[1], v = e[2];
        if (djs.findUParent(u) != djs.findUParent(v)) {
            ans += wt;
            djs.unionBySize(u, v);
        }
    }

    return ans;
}
