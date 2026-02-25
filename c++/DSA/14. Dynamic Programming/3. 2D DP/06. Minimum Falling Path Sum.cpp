/*
QUESTION:-
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, mat, dp) that calculates the minimum sum of any falling path starting from cell (i, j).
3. The function checks if the minimum sum for the current cell (i, j) is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i is 0, it means we are at the first row, so the minimum sum starting from this cell is the value in the current cell (mat[i][j]).
5. Otherwise, the function calculates the minimum sum for the current cell by taking the minimum of the minimum sums of the cells above it (i-1, j-1), (i-1, j), and (i-1, j+1), and then adding the value in the current cell (mat[i][j]).
6. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.
7. Finally, we find the minimum falling path sum for all cells in the first row and return the smallest value.

Complexity Analysis:
- The time complexity of the fmemo function is O(n^2) since we are calculating the minimum sum for each cell only once and storing it in the dp array.
- The space complexity is also O(n^2) to store the dp array.

*/

// Memoization
int fmemo(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (j < 0 || j >= mat[0].size())
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0)
        return dp[i][j] = mat[i][j];

    int a = fmemo(i - 1, j - 1, mat, dp);
    int b = fmemo(i - 1, j, mat, dp);
    int c = fmemo(i - 1, j + 1, mat, dp);

    return dp[i][j] = min(a, min(b, c)) + mat[i][j];
}

// Tabulation
int ftab(int n, vector<vector<int>>& mat){
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0){
                dp[i][j] = mat[i][j];
                continue;
            }
            int a = 1e9, c = 1e9;
            if(j-1>=0) a = dp[i-1][j-1];
            int b = dp[i-1][j];
            if(j+1<n) c = dp[i-1][j+1];
            dp[i][j] = min(a,min(b,c))+mat[i][j];
        }
    }
    int ans = INT_MAX;
    for(auto i:dp[n-1]) ans = min(ans,i);
    return ans;
}

// Space Optmization
int fopt(int n, vector<vector<int>>& mat){
    vector<int> prev(n);
    for(int i=0; i<n; i++){
        vector<int> curr(n);
        for(int j=0; j<n; j++){
            if(i==0){
                curr[j] = mat[i][j];
                continue;
            }
            int a = 1e9, c = 1e9;
            if(j-1>=0) a = prev[j-1];
            int b = prev[j];
            if(j+1<n) c = prev[j+1];
            curr[j] = min(a,min(b,c))+mat[i][j];
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(auto i:prev) ans = min(ans,i);
    return ans;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, fmemo(n - 1, i, matrix, dp));
    }

    return ans;
}
