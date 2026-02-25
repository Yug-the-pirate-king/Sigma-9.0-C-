/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

Example:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

APPROACH:
- This problem can be solved using dynamic programming.
- We need to keep track of whether we are holding a stock or not on each day.
- Define a 2D DP array `dp` where dp[i][hold] represents the maximum profit achievable starting from day i while holding or not holding a stock.
- The base case is dp[n][0] = dp[n][1] = 0, where n is the number of days.
- Iterate through each day i.
- If holding a stock, we can either sell the stock or continue holding.
- If not holding a stock, we can either buy the stock or continue not holding.
- Return dp[0][0], which represents the maximum profit achievable starting from day 0 while not holding a stock.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n), where n is the number of days.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n) time and O(n) space.

CODE:
*/

int f;
int fmemo(int i, int hold, vector<int>& prices, vector<vector<int>>& dp){
    if(i == prices.size()) return 0;

    if(dp[i][hold] != -1) return dp[i][hold];

    if(hold){
        // sell 
        int a = prices[i] - f + fmemo(i + 1, 0, prices, dp);
        // not sell
        int b = fmemo(i + 1, 1, prices, dp);
        return dp[i][hold] = max(a, b);
    }
    else{
        // buy
        int a = -prices[i] + fmemo(i + 1, 1, prices, dp);
        // not buy
        int b = fmemo(i + 1, 0, prices, dp);
        return dp[i][hold] = max(a, b);
    }
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    f = fee;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fmemo(0, 0, prices, dp);
}
