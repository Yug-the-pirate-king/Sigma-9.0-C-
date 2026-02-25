/*
QUESTION:
Given two strings s and t, return the number of distinct subsequences of s which equals t.

APPROACH:
- The problem can be solved using dynamic programming.
- Let dp[i][j] represent the number of distinct subsequences of the first i characters of string s that match the first j characters of string t.
- If s[i] equals t[j], we have two choices: we can either include the current character (s[i]) in the subsequence, in which case we add dp[i-1][j-1] to our count, or we can exclude it and move on, so we add dp[i-1][j] to our count.
- If s[i] doesn't match t[j], we have no choice but to exclude s[i], so we add dp[i-1][j] to our count.
- Base cases: When j equals -1 (meaning we've matched all characters of t), return 1. When i equals -1 (meaning we've exhausted all characters of s), return 0.
- Return dp[n-1][m-1], where n is the length of s and m is the length of t.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n * m), where n is the length of string s and m is the length of string t.
- The space complexity is O(n * m) due to the dp array.
- Overall, the algorithm runs in O(n * m) time and O(n * m) space.

CODE:
*/

int fmemo(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    if (j < 0) return 1;
    if (i < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = fmemo(i - 1, j - 1, s, t, dp) + fmemo(i - 1, j, s, t, dp);
    else
        return dp[i][j] = fmemo(i - 1, j, s, t, dp);
}

int ftab(int n, int m, string& s, string& t){
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n-1][m-1];
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fmemo(n - 1, m - 1, s, t, dp);
}
