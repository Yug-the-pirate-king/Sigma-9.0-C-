/*
QUESTION:-
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Example 1:
Input: m = 3, n = 7
Output: 28

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, dp) that calculates the number of unique paths from the top-left corner (0, 0) to the cell (i, j) on the grid.
3. The function checks if the number of unique paths for the cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the number of unique paths for the cell (i, j) by adding the number of unique paths from the cell above (i-1, j) and the cell to the left (i, j-1).
5. The base case is when i or j is less than 0, in which case the function returns 0 as there are no paths to reach those cells.
6. In the main function uniquePaths(m, n), we create a dp array of size m x n initialized with -1 and call the fmemo function for the bottom-right cell (m-1, n-1).
7. Finally, we return the number of unique paths obtained for the bottom-right cell as the result.

Complexity Analysis:
- The time complexity of the fmemo function is O(m x n) because we are calculating the number of unique paths for each cell only once and storing it in the dp array.
- The space complexity is also O(m x n) to store the dp array.

Note: The given test cases are generated such that the answer will be less than or equal to 2 x 10^9.
*/

//Memeoization
int fmemo(int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int top = fmemo(i - 1, j, dp);
    int left = fmemo(i, j - 1, dp);
    return dp[i][j] = top + left;
}

//Tabulation
int ftab(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) continue;
            int top = 0, left = 0;
            if(i-1>=0) top = top = dp[i-1][j];
            if(j-1>=0) left = dp[i][j-1];
            dp[i][j] = top+left;
        }
    }
    return dp[m-1][n-1];
}

//Space Optimization
int fopt(int m, int n){
    vector<int> prev(n);
    prev[0] = 1;
    for(int i=0; i<m; i++){
        vector<int> curr(n);
        curr[0] = 1;
        for(int j=0; j<n; j++){
            if(i==0 && j==0) continue;
            int top = 0, left = 0;
            if(i-1>=0) top = top = prev[j];
            if(j-1>=0) left = curr[j-1];
            curr[j] = top+left;
        }
        prev = curr;
    }
    return prev[n-1];
}


int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fmemo(m - 1, n - 1, dp);
}

