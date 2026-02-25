/*
QUESTION:
Given an integer array 'coins' representing coins of different 
denominations and an integer 'amount' representing a total amount 
of money, the task is to return the number of combinations that 
make up that amount using the given coins. If that amount of money 
cannot be made up by any combination of the coins, return 0.

Example:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: There are four ways to make up the amount:
5 = 5
5 = 2 + 2 + 1
5 = 2 + 1 + 1 + 1
5 = 1 + 1 + 1 + 1 + 1

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the number 
  of combinations to make up amount 'j' using the first 'i' coins.
- Base case:
  - dp[i][0] = 1 for all 'i' (one way to make 0 amount with any coin)
- For each coin 'i' and each possible amount 'j':
  - dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
- The required answer will be dp[n][amount] where 'n' is the number 
  of coins and 'amount' is the given total amount.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(N * amount), where 'N' is 
  the number of coins and 'amount' is the given total amount.
- The space complexity is O(N * amount) for the dp array.

CODE:
*/

// Memoization
int fmemo(int i, int tar, vector<int>& arr, vector<vector<int>>& dp){
    if(i == 0){
        if(tar % arr[i] != 0) return 0;
        return 1;
    }

    if(dp[i][tar] != -1) return dp[i][tar];

    int take = 0;
    if(arr[i] <= tar) take = fmemo(i, tar - arr[i], arr, dp);
    int notake = fmemo(i - 1, tar, arr, dp);
    
    return dp[i][tar] = (take + notake);
}

// Tabulation
 int ftab(int n, int amount, vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(amount+1));
    for(int i=0; i<n; i++){
        for(int tar=0; tar<=amount; tar++){
            if(i == 0){
                if(tar % arr[i]!=0) dp[i][tar] = 0;
                else dp[i][tar] = 1;
                continue;
            }
            int take = 0;
            if(arr[i] <= tar) take = dp[i][tar-arr[i]];
            int notake = dp[i-1][tar];
            dp[i][tar] = (take + notake);
        }
    }
    return dp[n-1][amount];
}

// Space Optimization
int fopt(int n, int amount, vector<int>& arr){
    vector<int> prev(amount+1);
    for(int i=0; i<n; i++){
        vector<int> curr(amount+1);
        for(int tar=0; tar<=amount; tar++){
            if(i == 0){
                if(tar % arr[i]!=0) curr[tar] = 0;
                else curr[tar] = 1;
                continue;
            }
            int take = 0;
            if(arr[i] <= tar) take = curr[tar-arr[i]];
            int notake = prev[tar];
            curr[tar] = (take + notake);
        }
        prev = curr;
    }
    return prev[amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return fmemo(n - 1, amount, coins, dp);
}
