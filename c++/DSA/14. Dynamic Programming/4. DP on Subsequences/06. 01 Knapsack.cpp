/*
QUESTION:
Given weights and values of 'N' items, the task is to put these 
items in a knapsack of capacity 'W' to get the maximum total value 
in the knapsack. The constraint is that each item can either be 
picked completely or not at all (0-1 property).

Example:
Input: 
N = 3
W = 4
values[] = {1, 2, 3}
weight[] = {4, 5, 1}
Output: 3

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the 
  maximum value that can be obtained using the first 'i' items 
  and having a knapsack capacity of 'j'.
- Base cases:
  - dp[0][j] = 0 for all j (no items available)
  - dp[i][0] = 0 for all i (no capacity)
- For each item 'i' and each possible capacity 'j':
  - If the weight of the current item is less than or equal to 'j':
    - dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wt[i]])
  - Otherwise, dp[i][j] = dp[i-1][j] (item cannot be included)
- The required answer will be dp[N][W] where 'N' is the number of items 
  and 'W' is the knapsack capacity.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(N * W), where 'N' is the 
  number of items and 'W' is the knapsack capacity.
- The space complexity is O(N * W) for the dp array.

CODE:
*/

// Memoization
int fmemo(int i, int val[], int wt[], int W, vector<vector<int>>& dp){
    if(i == 0){
        if(W >= wt[i]) return dp[i][W] = val[i];
        else return dp[i][W] = 0;
    }
    
    if(dp[i][W] != -1) return dp[i][W];
    
    int take = INT_MIN;
    if(W >= wt[i]) take = val[i] + fmemo(i-1, val, wt, W - wt[i], dp);
    int notake = fmemo(i-1, val, wt, W, dp);
    
    return dp[i][W] = max(take, notake);
}

// Tabulation
int ftab(int n, int val[], int wt[], int weight){
    vector<vector<int>> dp(n,vector<int>(weight+1));
    for(int i=0; i<n; i++){
        for(int W=0; W<=weight; W++){
            if(i==0){
                if(W >= wt[i]) dp[i][W] = val[i];
                else dp[i][W] = 0;
                continue;
            }
            int take = INT_MIN;
            if(W >= wt[i]) take = val[i]+dp[i-1][W-wt[i]];
            int notake = dp[i-1][W];
            dp[i][W] = max(take,notake);
        }
    }
    return dp[n-1][weight];
}

// Space Optimization
int fopt(int n, int val[], int wt[], int weight){
    vector<int> prev(weight+1);
    for(int i=0; i<n; i++){
        vector<int> curr(weight+1);
        for(int W=0; W<=weight; W++){
            if(i==0){
                if(W >= wt[i]) curr[W] = val[i];
                else curr[W] = 0;
                continue;
            }
            int take = INT_MIN;
            if(W >= wt[i]) take = val[i]+prev[W-wt[i]];
            int notake = prev[W];
            curr[W] = max(take,notake);
        }
        prev = curr;
    }
    return dp[n-1][weight];
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return fmemo(n - 1, val, wt, W, dp);
}
