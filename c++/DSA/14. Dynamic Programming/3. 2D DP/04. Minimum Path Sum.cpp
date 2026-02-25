/*
QUESTION:-
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, grid, dp) that calculates the minimum sum path to reach the cell (i, j) on the grid.
3. The function checks if the minimum sum path for the cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i or j is less than 0 (out of bounds), the function returns a large value (e.g., 1e9) to represent an invalid path.
5. The base case is when i and j are both 0, in which case the function returns the value in the cell (0, 0) as the minimum sum path.
6. Otherwise, it calculates the minimum sum path for the cell (i, j) by taking the minimum of the minimum sum paths from the cell above (i-1, j) and the cell to the left (i, j-1), and then adding the value in the current cell (grid[i][j]).
7. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.

Complexity Analysis:
- The time complexity of the fmemo function is O(m x n) because we are calculating the minimum sum path for each cell only once and storing it in the dp array.
- The space complexity is also O(m x n) to store the dp array.

*/

// Memoization
int fmemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0 && j == 0)
        return dp[i][j] = grid[i][j];

    int top = fmemo(i - 1, j, grid, dp);
    int left = fmemo(i, j - 1, grid, dp);
    return dp[i][j] = min(top, left) + grid[i][j];
}

// Tabulation
int ftab(int m, int n, vector<vector<int>>& grid){
    vector<vector<int>> dp(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int top = 1e9, left = 1e9;
            if(i-1>=0) top = dp[i-1][j];
            if(j-1>=0) left = dp[i][j-1];
            dp[i][j] = min(top,left)+grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

// Space Optimization
int fopt(int m, int n, vector<vector<int>>& grid){
    vector<int> prev(n);
    for(int i=0; i<m; i++){
        vector<int> curr(n);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                curr[j] = grid[i][j];
                continue;
            }
            int top = 1e9, left = 1e9;
            if(i-1>=0) top = prev[j];
            if(j-1>=0) left = curr[j-1];
            curr[j] = min(top,left)+grid[i][j];
        }
        prev = curr;
    }
    return prev[n-1];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fmemo(m - 1, n - 1, grid, dp);
}
