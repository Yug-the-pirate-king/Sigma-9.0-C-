/*
QUESTION:-
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

APPROACH:
- We can use Depth-First Search (DFS) to find all regions that are surrounded by 'X'.
- First, we initialize a copy of the board called 'vis' to store the visited status of each cell.
- Then, we perform a DFS starting from all border cells that have 'O's. During the DFS, we mark all connected 'O's as visited by changing them to a special character, such as '#', in the 'vis' matrix.
- After performing DFS from border cells, all remaining '#'s in the 'vis' matrix represent regions that are not surrounded by 'X'.
- Finally, we update the original board by flipping all remaining 'O's to 'X'.

COMPLEXITY ANALYSIS:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. In the worst case, we may need to visit all the cells of the matrix during DFS.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. We use additional space for the 'vis' matrix.
*/

void dfs(int i, int j, vector<vector<char>>& vis){
    if(i >= 0 && i < vis.size() && j >= 0 && j < vis[0].size() && vis[i][j] == 'O'){
        vis[i][j] = '#';
        dfs(i + 1, j, vis);
        dfs(i - 1, j, vis);
        dfs(i, j + 1, vis);
        dfs(i, j - 1, vis);
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<char>> vis(board.begin(), board.end());
    
    // Perform DFS from border cells
    for(int i = 0; i < n; i++){
        if(vis[0][i] == 'O')
            dfs(0, i, vis);
        if(vis[m - 1][i] == 'O')
            dfs(m - 1, i, vis);
    }
    for(int i = 0; i < m; i++){
        if(vis[i][0] == 'O')
            dfs(i, 0, vis);
        if(vis[i][n - 1] == 'O')
            dfs(i, n - 1, vis);
    }
    
    // Update the original board
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}
