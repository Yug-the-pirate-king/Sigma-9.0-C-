/*
QUESTION:
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

APPROACH:
- This problem can be solved using dynamic programming.
- We need to find the count of square submatrices with all ones.
- Define a 2D DP array `dp` where dp[i][j] represents the side length of the largest square ending at (i, j).
- The base case is dp[i][0] = matrix[i][0] and dp[0][j] = matrix[0][j].
- Iterate through each cell (i, j) in the matrix starting from (1, 1).
- If matrix[i][j] is 1, update dp[i][j] as the minimum of (dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1.
- Add dp[i][j] to the `ans` variable to keep track of the total count of squares.
- Return the `ans`.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
- The space complexity is O(m * n) due to the dp array.
- Overall, the algorithm runs in O(m * n) time and O(m * n) space.

CODE:
*/

int ftab(int m, int n, vector<vector<int>>& matrix){
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i-1][j-1] == 1){
                int temp = min(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] = min(dp[i][j-1], temp) + 1;
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    return ftab(m, n, matrix);
}
