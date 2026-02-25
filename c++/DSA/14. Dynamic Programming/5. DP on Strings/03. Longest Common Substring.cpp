/*
QUESTION:
Given two strings. The task is to find the length of the longest common substring.

Example:
Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the length of 
  the longest common suffix of substrings S1[0..i-1] and S2[0..j-1].
- Initialize a variable 'maxi' to keep track of the maximum length found.
- For each character at index 'i' in S1 and each character at index 'j' 
  in S2:
  - If S1[i] == S2[j], then dp[i][j] = dp[i-1][j-1] + 1
  - Else, dp[i][j] = 0 (as no common suffix found)
  - Update 'maxi' with dp[i][j]
- The required answer will be 'maxi'.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n*m), where 'n' and 'm' are 
  the lengths of S1 and S2 respectively.
- The space complexity is O(n*m) for the dp array.

CODE:
*/

int maxi = 0;

int fmemo(int i, int j, string& s, string& r, vector<vector<int>>& dp){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == r[j]){
        dp[i][j] = fmemo(i - 1, j - 1, s, r, dp) + 1;
        maxi = max(maxi, dp[i][j]);
    }
    else dp[i][j] = 0;

    fmemo(i - 1, j, s, r, dp);
    fmemo(i, j - 1, s, r, dp);

    return dp[i][j];
}

int longestCommonSubstr(string S1, string S2, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    fmemo(n - 1, m - 1, S1, S2, dp);
    return maxi;
}
