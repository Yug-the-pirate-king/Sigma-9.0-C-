/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example:
Input: prices = [3, 3, 5, 0, 0, 3, 1, 4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3 - 0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4 - 1 = 3.

APPROACH:
- This problem can be solved using dynamic programming.
- We need to keep track of the number of transactions completed so far (cap) and whether we are holding a stock or not on each day.
- Define a 3D DP array `dp` where dp[i][hold][cap] represents the maximum profit achievable starting from day i while holding or not holding a stock and having completed cap transactions.
- The base case is dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 0, where n is the number of days.
- Iterate through each day i in reverse order.
- If holding a stock, we can either sell the stock or continue holding.
- If not holding a stock, we can either buy the stock or continue not holding.
- Return dp[0][0][0], which represents the maximum profit achievable starting from day 0 while not holding a stock and having completed 0 transactions.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n), where n is the number of days.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n) time and O(n) space.

CODE:
*/

int fmemo(int i, int hold, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if(i == prices.size()) return 0;
    if(cap == 3) return 0;

    if(dp[i][hold][cap] != -1) return dp[i][hold][cap];

    if(hold){
        // sell 
        int a = prices[i] + fmemo(i + 1, 0, cap, prices, dp);
        // not sell
        int b = fmemo(i + 1, 1, cap, prices, dp);
        return dp[i][hold][cap] = max(a, b);
    }
    else{
        // buy
        int a = -prices[i] + fmemo(i + 1, 1, cap + 1, prices, dp);
        // not buy
        int b = fmemo(i + 1, 0, cap, prices, dp);
        return dp[i][hold][cap] = max(a, b);
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return fmemo(0, 0, 0, prices, dp);
}
