/*
QUESTION:

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

APPROACH:

To solve this problem, we can use the Disjoint Set data structure to group stones that share the same row or column.
- First, we find the minimum and maximum row and column values to calculate the size of the grid.
- Then, we iterate through the stones and perform the union operation for stones that share the same row or column.
- Finally, we count the number of disjoint sets and subtract it from the total number of stones to get the maximum number of stones that can be removed.

COMPLEXITY ANALYSIS:

Let n be the number of stones and m be the size of the grid.

- Building the Disjoint Set: O(n)
- Finding the number of disjoint sets: O(n)
- Overall Time Complexity: O(n)
- Space Complexity: O(n) for the Disjoint Set data structure

CODE:-
*/


class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uP = findUPar(u), vP = findUPar(v);
        int uSize = size[uP], vSize = size[vP];
        if (uP == vP)
            return;
        if (uSize > vSize) {
            parent[vP] = uP;
            size[uP] += vSize;
        } else {
            parent[uP] = vP;
            size[vP] += uSize;
        }
    }

    int countComponents(int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (n - 1 > connections.size())
        return -1;

    DisjointSet djs(n);
    for (auto c : connections) {
        int u = c[0], v = c[1];
        if (djs.findUPar(u) != djs.findUPar(v))
            djs.unionBySize(u, v);
    }

    int components = djs.countComponents(n);
    return components - 1;
}