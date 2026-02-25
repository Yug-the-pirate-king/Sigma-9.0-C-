/*
QUESTION:
Given a set of N items, each with a weight and a value, represented 
by the arrays w[] and val[] respectively, and a knapsack with weight 
limit 'W', the task is to fill the knapsack in such a way that we 
can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example:
Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explanation: 
1. Pick the 2nd element thrice.
2. Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1 = 3 
   which is <= W.

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the maximum 
  profit that can be obtained by using items from 0 to 'i' with a total 
  weight of 'j'.
- Base case: dp[0][j] = j / wt[0] * val[0] (maximum profit with only 
  the first item)
- For each item 'i' and each possible total weight 'j':
  - dp[i][j] = max(dp[i-1][j], val[i] + dp[i][j - wt[i]])
- The required answer will be dp[N-1][W] where 'N' is the number of items 
  and 'W' is the given weight limit.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(N * W), where 'N' is the number 
  of items and 'W' is the given weight limit.
- The space complexity is O(N * W) for the dp array.

CODE:
*/

// Memoization
int fmemo(int i, int val[], int wt[], int W, vector<vector<int>>& dp){
    if(i == 0){
        if(W >= wt[i]){
            return dp[i][W] = (W / wt[i]) * val[i];
        }
        else return dp[i][W] = 0;
    }
    
    if(dp[i][W] != -1) return dp[i][W];
    
    int take = INT_MIN;
    if(W >= wt[i]) take = val[i] + fmemo(i, val, wt, W - wt[i], dp);
    int notake = fmemo(i - 1, val, wt, W, dp);
    
    return dp[i][W] = max(take, notake);
}

// Tabulation
int ftab(int n, int val[], int wt[], int weight){
    vector<vector<int>> dp(n,vector<int>(weight+1));
    for(int i=0; i<n; i++){
        for(int W=0; W<=weight; W++){
            if(i==0){
                if(W >= wt[i]) dp[i][W] = (W/wt[i])*val[i];
                else dp[i][W] = 0;
                continue;
            }
            int take = INT_MIN;
            if(W >= wt[i]) take = val[i]+dp[i][W-wt[i]];
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
                if(W >= wt[i]) curr[W] = (W/wt[i])*val[i];
                else curr[W] = 0;
                continue;
            }
            int take = INT_MIN;
            if(W >= wt[i]) take = val[i]+curr[W-wt[i]];
            int notake = prev[W];
            curr[W] = max(take,notake);
        }
        prev = curr;
    }
    return dp[n-1][weight];
}


int knapSack(int N, int W, int val[], int wt[]){
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return fmemo(N - 1, val, wt, W, dp);
}
