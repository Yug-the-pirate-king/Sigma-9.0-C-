/*
QUESTION:
Given a wooden stick of length n units. The stick is labelled from 0 to n.
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
Return the minimum total cost of the cuts.

Example:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts [1, 3, 4, 5] as the order, the total cost is 1 + 3 + 3 + 4 + 5 = 16.

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 2D DP array `dp` where dp[i][j] represents the minimum total cost to cut the stick between cuts[i] and cuts[j].
- Initialize dp[i][i] to 0 because there is no cost for a single cut.
- Iterate over the stick lengths from length 2 to the length of cuts + 1.
- For each stick length, iterate through all possible cut starting points (i).
- Calculate the cost for cutting the stick between cuts[i] and cuts[i + len - 1] and update the dp array.
- Finally, return dp[0][cuts.size() - 1], which represents the minimum total cost of the cuts.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^3), where n is the length of the cuts array.
- The space complexity is O(n^2) due to the dp array.
- Overall, the algorithm runs in O(n^3) time and O(n^2) space.

CODE:
*/

int fmemo(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i; k <= j; k++){
        int cost = (cuts[j + 1] - cuts[i - 1]) + fmemo(i, k - 1, cuts, dp) + fmemo(k + 1, j, cuts, dp);
        mini = min(cost, mini);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& cuts) {
    vector<int> cut;
    cut.push_back(0);
    for(auto i : cuts)
        cut.push_back(i);
    cut.push_back(n);
    sort(cut.begin(), cut.end());
    int s = cut.size();
    vector<vector<int>> dp(s, vector<int>(s, -1));
    int i = 1, j = cuts.size();
    return fmemo(i, j, cut, dp);
}
