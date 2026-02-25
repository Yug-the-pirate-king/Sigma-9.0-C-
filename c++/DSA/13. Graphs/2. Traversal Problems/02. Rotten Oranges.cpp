/*
Question: 

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Approach:

1. Use Breadth-First Search (BFS) to rot the oranges.
2. Initialize a queue to store the rotten oranges.
3. Iterate through the grid to find the rotten oranges and count the number of fresh oranges.
4. Perform BFS starting from each rotten orange and keep track of the time required to rot all the fresh oranges.
5. For each level in BFS (each minute), check adjacent cells to a rotten orange and mark them as rotten if they contain a fresh orange. Decrease the fresh count and add the newly rotten oranges to the queue.
6. Repeat this process until all fresh oranges are rotten or the queue is empty.
7. Return the time required (minutes) if all fresh oranges are rotten, otherwise, return -1.

Time Complexity: O(m * n) - where 'm' is the number of rows and 'n' is the number of columns in the grid.
Space Complexity: O(m * n) - due to the queue and the grid.

Code:
*/

int orangesRotting(vector<vector<int>>& grid) {
    int ans = -1, fresh = 0, m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
            if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if(fresh == 0) {
        return 0;
    }

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while(!q.empty()) {
        int k = q.size();
        while(k--) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            for(int i = 0; i < 4; i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
        ans++;
    }

    return (fresh > 0) ? -1 : ans;
}
