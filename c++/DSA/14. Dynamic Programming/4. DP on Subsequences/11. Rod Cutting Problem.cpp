/*
QUESTION:
Given a rod of length 'N' inches and an array of prices 'price[]', where 
price[i] denotes the value of a piece of length 'i', determine the maximum 
value obtainable by cutting up the rod and selling the pieces.

Example:
Input: N = 8, Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces 
             of lengths 2 and 6, i.e., 5 + 17 = 22.

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the maximum 
  value obtainable by cutting a rod of length 'i' with available pieces 
  up to length 'j'.
- Base case: dp[0][j] = 0 (no rod, so value is 0)
- For each length 'i' and each possible total length 'j':
  - dp[i][j] = max(dp[i-1][j], price[i] + dp[i][j - i])
- The required answer will be dp[N][N] where 'N' is the given length of 
  the rod.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(N^2), where 'N' is the length 
  of the rod.
- The space complexity is O(N^2) for the dp array.

CODE:
*/

// Memeoization
int fmemo(int i, int val[], int W, vector<vector<int>>& dp){
    if(i == 1){
        return (W / i) * val[i - 1];
    }
    
    if(dp[i][W] != -1) return dp[i][W];
    
    int take = INT_MIN;
    if(W >= i) take = val[i - 1] + fmemo(i, val, W - i, dp);
    int notake = fmemo(i - 1, val, W, dp);
    
    return dp[i][W] = max(take, notake);
}

// Tabulation
int ftab(int n, int val[]){
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1; i<n; i++){
        for(int W=0; W<=n; W++){
            if(i==1){
                dp[i][W] = (W / i) * val[i - 1];
                continue;
            }
            int take = INT_MIN;
            if(W >= i) take = val[i]+dp[i][W-i];
            int notake = dp[i-1][W];
            dp[i][W] = max(take,notake);
        }
    }
    return dp[n][n];
}

int cutRod(int price[], int N) {
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return fmemo(N, price, N, dp);
}
