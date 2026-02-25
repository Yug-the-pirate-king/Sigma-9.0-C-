/*
QUESTION:-
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Approach:
1. We use a priority queue (min heap) to keep track of the cells in increasing order of their elevations.
2. Start from the top left cell (0, 0) and add it to the priority queue with its elevation as the key.
3. Mark this cell as visited.
4. While the priority queue is not empty, pop the cell with the minimum elevation.
5. Update the answer with the maximum of the current elevation and the answer so far.
6. Check the 4-directionally adjacent cells of the current cell.
7. If the adjacent cell is within the boundaries and not visited, add it to the priority queue with its elevation as the key.
8. Mark the adjacent cell as visited.
9. Continue the process until we reach the bottom right cell (n-1, n-1).
10. The answer at this point will be the least time until we can reach the bottom right cell.

Complexity Analysis:
- We need to visit all cells of the grid, so the time complexity of the solution is O(n^2).
- We use a priority queue to store at most n^2 cells, so the space complexity is also O(n^2).

CODE:-
*/

typedef pair<int, pair<int, int>> dup;

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<bool>> vis(n, vector<bool>(n));
    priority_queue<dup, vector<dup>, greater<dup>> pq;
    pq.push({grid[0][0], {0, 0}});
    vis[0][0] = true;

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    int ans = 0;

    while (!pq.empty()) {
        auto [uwt, cord] = pq.top();
        pq.pop();
        int x = cord.first, y = cord.second;
        ans = max(ans, uwt);
        if (x == n - 1 && y == n - 1) return ans;
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});
            }
        }
    }

    return ans;
}
