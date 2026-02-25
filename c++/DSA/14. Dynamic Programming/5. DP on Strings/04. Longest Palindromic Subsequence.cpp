/*
QUESTION:
Given a string s, find the longest palindromic subsequence's length in s.

Example:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

APPROACH:
- This problem can be solved using Dynamic Programming (DP).
- Initialize a 2D DP array 'dp' where dp[i][j] represents the length of 
  the longest palindromic subsequence in the substring s[i..j].
- For each character at index 'i' and each character at index 'j':
  - If s[i] == s[j], then dp[i][j] = dp[i+1][j-1] + 2
  - Else, dp[i][j] = max(dp[i+1][j], dp[i][j-1])
- The required answer will be dp[0][n-1], where 'n' is the length of 's'.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n^2), where 'n' is the length of the input string.
- The space complexity is O(n^2) for the dp array.

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

int longestPalindromeSubseq(string s) {
    int n = s.size();
    string r = s;
    reverse(r.begin(),r.end());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fmemo(n-1,n-1,s,r,dp);
}
