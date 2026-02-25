/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example:
Input: prices = [1, 2, 3, 0, 2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

APPROACH:
- This problem can be solved using dynamic programming.
- We need to keep track of whether we are holding a stock or not on each day.
- Define a 2D DP array `dp` where dp[i][hold] represents the maximum profit achievable starting from day i while holding or not holding a stock.
- The base case is dp[n][0] = dp[n][1] = 0, where n is the number of days.
- Iterate through each day i in reverse order.
- If holding a stock, we can either sell the stock or continue holding.
- If not holding a stock, we can either buy the stock or continue not holding.
- Return dp[0][0], which represents the maximum profit achievable starting from day 0 while not holding a stock.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n), where n is the number of days.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n) time and O(n) space.

CODE:
*/

int fmemo(int i, int hold, vector<int>& prices, vector<vector<int>>& dp){
    if(i >= prices.size()) return 0;

    if(dp[i][hold] != -1) return dp[i][hold];

    if(hold){
        // sell 
        int a = prices[i] + fmemo(i + 2, 0, prices, dp);
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

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fmemo(0, 0, prices, dp);
}
