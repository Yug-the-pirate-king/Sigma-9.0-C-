/* QUESTION:

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
1. All the visited cells of the path are 0.
2. All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
3. The length of a clear path is the number of visited cells of this path.

Example:
Input: grid = [[0,1],[1,0]]
Output: 2

APPROACH:
- We can use Breadth-First Search (BFS) to find the shortest path.
- Start BFS from the top-left cell (0, 0) and explore its neighboring cells in 8 directions.
- Mark the visited cells and continue BFS until reaching the bottom-right cell (n - 1, n - 1).
- The number of levels traversed in BFS will represent the length of the shortest clear path.
- If the bottom-right cell cannot be reached or there is no clear path, return -1.

COMPLEXITY ANALYSIS:
- The time complexity of BFS is O(n^2) as it explores all cells in the n x n matrix.
- The space complexity is also O(n^2) due to the usage of the queue and the visited matrix.

CODE:
*/

bool isValid(int x, int y, int n, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
    return (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 0);
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
    
    vector<vector<bool>> vis(n, vector<bool>(n));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    int lvl = 1;
    
    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if (x == n - 1 && y == n - 1) return lvl;
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + i, ny = y + j;
                    if (isValid(nx, ny, n, vis, grid)) {
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        lvl++;
    }
    return -1;
}
