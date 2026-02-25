/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

APPROACH:
- Initialize a variable minprice with the price on the first day and initialize ans to 0.
- Iterate through the array from the second day to the last day.
- Update ans with the maximum of its current value and the difference between the current price and minprice.
- Update minprice with the minimum of its current value and the current price.
- Return the final value of ans.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n), where n is the length of the prices array.
- The space complexity is O(1) as we are using constant extra space.
- Overall, the algorithm runs in O(n) time and O(1) space.

CODE:
*/

int maxProfit(vector<int>& prices) {
    int minprice = prices[0];
    int ans = 0;
    for(int i = 1; i < prices.size(); i++){
        ans = max(ans, prices[i] - minprice);
        minprice = min(minprice, prices[i]);
    }
    return ans;
}
