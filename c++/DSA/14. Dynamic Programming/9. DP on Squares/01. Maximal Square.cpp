/*
QUESTION:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

APPROACH:
- This problem can be solved using dynamic programming.
- We need to find the largest square containing only 1's.
- Define a 2D DP array `dp` where dp[i][j] represents the side length of the largest square ending at (i, j).
- The base case is dp[i][0] = matrix[i][0] and dp[0][j] = matrix[0][j].
- Iterate through each cell (i, j) in the matrix starting from (1, 1).
- If matrix[i][j] is '1', update dp[i][j] as the minimum of (dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1.
- Update the maximum side length `maxSide` accordingly.
- Return `maxSide * maxSide`, which is the area of the largest square containing only 1's.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
- The space complexity is O(m * n) due to the dp array.
- Overall, the algorithm runs in O(m * n) time and O(m * n) space.

CODE:
*/

int ftab(int m, int n, vector<vector<char>>& matrix){
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxSide = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i-1][j-1] == '1'){
                int temp = min(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] = min(dp[i][j-1], temp) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    return ftab(m, n, matrix);
}
