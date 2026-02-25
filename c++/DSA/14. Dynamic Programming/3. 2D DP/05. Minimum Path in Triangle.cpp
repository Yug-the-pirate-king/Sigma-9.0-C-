/*
QUESTION:-
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, j, n, tri, dp) that calculates the minimum path sum from the current cell (i, j) to the bottom of the triangle.
3. The function checks if the minimum path sum for the current cell is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. If i is equal to n-1, it means we are at the last row of the triangle, so the minimum path sum is the value in the current cell (tri[i][j]).
5. Otherwise, the function calculates the minimum path sum for the current cell by taking the minimum of the minimum path sums from the cells directly below (i+1, j) and (i+1, j+1), and then adding the value in the current cell (tri[i][j]).
6. The result is stored in the dp array to avoid recomputation when the function is called with the same parameters again.

Complexity Analysis:
- The time complexity of the fmemo function is O(n^2) because we are calculating the minimum path sum for each cell only once and storing it in the dp array.
- The space complexity is also O(n^2) to store the dp array.

*/

// Memoization
int fmemo(int i, int j, int n, vector<vector<int>>& tri, vector<vector<int>>& dp) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return dp[i][j] = tri[i][j];

    int a = fmemo(i + 1, j, n, tri, dp);
    int b = fmemo(i + 1, j + 1, n, tri, dp);
    return dp[i][j] = min(a, b) + tri[i][j];
}

// Tabulation
int ftab(int n, vector<vector<int>>& tri){
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(i==n-1){
                dp[i][j] = tri[i][j];
                continue;
            }
            int a = dp[i+1][j];
            int b = dp[i+1][j+1];
            dp[i][j] = min(a,b)+tri[i][j];
        }
    }
    return dp[0][0];
}

// Space Optimization
int fopt(int n, vector<vector<int>>& tri){
    vector<int> prev(n);
    for(int i=n-1; i>=0; i--){
        vector<int> curr(n);
        for(int j=i; j>=0; j--){
            if(i==n-1){
                curr[j] = tri[i][j];
                continue;
            }
            int a = prev[j];
            int b = prev[j+1];
            curr[j] = min(a,b)+tri[i][j];
        }
        prev = curr;
    }
    return prev[0];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fmemo(0, 0, n, triangle, dp);
}
