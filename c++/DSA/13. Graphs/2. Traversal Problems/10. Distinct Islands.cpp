/*
QUESTION:
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

APPROACH:
- We can model this problem as a graph where each group of connected 1s forms an island.
- We can use Depth-First Search (DFS) to traverse the grid and identify each island.
- During the DFS, we keep track of the path taken to traverse each island. The path can be represented as a string, where each character in the string represents the direction of movement during the DFS (U for Up, D for Down, R for Right, and L for Left).
- We use a set to store the paths of all distinct islands. As sets store unique elements, we will have only unique paths in the set.
- Finally, we return the size of the set, which gives us the number of distinct islands.

COMPLEXITY ANALYSIS:
- Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the grid. We visit each cell at most once during the DFS.
- Space Complexity: O(n * m), where n is the number of rows and m is the number of columns in the grid. We use additional space to store the visited status of each cell and the paths of the islands in the set.
*/

void dfs(int i, int j, vector<vector<int>>& grid, string& path, vector<vector<bool>>& vis){
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1 && !vis[i][j]){
        vis[i][j] = true;
        dfs(i + 1, j, grid, path += "U", vis);
        dfs(i - 1, j, grid, path += "D", vis);
        dfs(i, j + 1, grid, path += "R", vis);
        dfs(i, j - 1, grid, path += "L", vis);
    }  
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    
    unordered_set<string> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                string path = "";
                dfs(i, j, grid, path, vis);
                st.insert(path);
            }
        }
    }
    
    return st.size();
}
