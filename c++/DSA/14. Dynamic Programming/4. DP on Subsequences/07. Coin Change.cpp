/*
QUESTION:
Given an integer array 'coins' representing coins of different 
denominations and an integer 'amount' representing a total amount 
of money, the task is to return the fewest number of coins that 
you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

Example:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the minimum 
  number of coins needed to make up amount 'j' using the first 'i' coins.
- Base case:
  - dp[i][0] = 0 for all 'i' (no coins needed to make 0 amount)
  - dp[0][j] = 1e9 (no way to make up any amount using 0 coins)
- For each coin 'i' and each possible amount 'j':
  - dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i]] + 1)
- The required answer will be dp[n][amount] where 'n' is the number 
  of coins and 'amount' is the given total amount.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(N * amount), where 'N' is 
  the number of coins and 'amount' is the given total amount.
- The space complexity is O(N * amount) for the dp array.

CODE:
*/

// Memoization
int fmemo(int i, int amt, vector<int>& coins, vector<vector<int>>& dp){
    if(amt == 0) return 0;
    if(i == 0){
        if(amt % coins[i] == 0) return amt / coins[i];
        else return 1e9;
    }

    if(dp[i][amt] != -1) return dp[i][amt];

    int take = 1e9;
    if(coins[i] <= amt) take = 1 + fmemo(i, amt - coins[i], coins, dp);
    int notake = fmemo(i - 1, amt, coins, dp);
    
    return dp[i][amt] = min(take, notake);
}

// Tabulation
int ftab(int n, int amount, vector<int>& coins){
    vector<vector<int>> dp(n,vector<int>(amount+1));
    for(int i=0; i<n; i++){
        for(int amt=0; amt<=amount; amt++){
            if(amt==0) {
                dp[i][amt] = 0;
                continue;
            }
            if(i==0){
                if(amt%coins[i]==0) dp[i][amt] =  amt/coins[i];
                else dp[i][amt] = 1e9;
                continue;
            }
            int take = 1e9;
            if(coins[i]<=amt) take = 1+dp[i][amt-coins[i]];
            int notake = dp[i-1][amt];
            dp[i][amt] = min(take,notake);
        }
    }
    return dp[n-1][amount];
}

// Space Optimization
int fopt(int n, int amount, vector<int>& coins){
    vector<int> prev(amount+1);
    for(int i=0; i<n; i++){
        vector<int> curr(amount+1);
        for(int amt=0; amt<=amount; amt++){
            if(amt==0) {
                curr[amt] = 0;
                continue;
            }
            if(i==0){
                if(amt%coins[i]==0) curr[amt] =  amt/coins[i];
                else curr[amt] = 1e9;
                continue;
            }
            int take = 1e9;
            if(coins[i]<=amt) take = 1+curr[amt-coins[i]];
            int notake = prev[amt];
            curr[amt] = min(take,notake);
        }
        prev = curr;
    }
    return prev[amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = fmemo(n - 1, amount, coins, dp);
    return (ans == 1e9) ? -1 : ans;
}
