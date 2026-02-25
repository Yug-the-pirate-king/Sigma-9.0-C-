/*
QUESTION:
Given two strings 'text1' and 'text2', return the length of their longest 
common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original 
string with some characters (can be none) deleted without changing the 
relative order of the remaining characters.

Example:
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the length of 
  the longest common subsequence between the prefixes text1[0..i] and 
  text2[0..j].
- Base case: dp[i][0] = 0 (empty second string) and dp[0][j] = 0 
  (empty first string).
- For each character at index 'i' in text1 and each character at index 
  'j' in text2:
  - If text1[i] == text2[j], then dp[i][j] = dp[i-1][j-1] + 1
  - Else, dp[i][j] = max(dp[i-1][j], dp[i][j-1])
- The required answer will be dp[n-1][m-1] where 'n' is the length of 
  text1 and 'm' is the length of text2.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n*m), where 'n' and 'm' are 
  the lengths of text1 and text2 respectively.
- The space complexity is O(n*m) for the dp array.

CODE:
*/

// Memoization
int fmemo(int i, int j, string& s, string& r, vector<vector<int>>& dp){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == r[j]) return dp[i][j] = fmemo(i - 1, j - 1, s, r, dp) + 1;
    else return dp[i][j] = max(fmemo(i - 1, j, s, r, dp), fmemo(i, j - 1, s, r, dp));
}

// Tabulation
int ftab(int n, int m, string& s, string& r){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==r[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Space Optimization
int fopt(int n, int m, string& s, string& r){
    vector<int> prev(m+1,0);
    for(int i=1; i<=n; i++){
        vector<int> curr(m+1,0);
        for(int j=1; j<=m; j++){
            if(s[i-1]==r[j-1]) curr[j] = prev[j-1]+1;
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fmemo(n - 1, m - 1, text1, text2, dp);
}
