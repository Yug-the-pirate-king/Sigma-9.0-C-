/*
QUESTION:
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

APPROACH:
- The problem can be reduced to finding the length of the Longest Common Subsequence (LCS) between the two strings.
- The idea is to find the length of the LCS and then subtracting it from the sum of the lengths of the two strings.
- The reason is that the characters not present in the LCS need to be deleted from both strings to make them the same.
- Therefore, the minimum number of steps required is equal to the sum of the lengths of the strings minus twice the length of the LCS.

COMPLEXITY ANALYSIS:
- The time complexity of finding the LCS is O(n*m), where n and m are the lengths of the two strings.
- The space complexity is O(n*m) due to the dp array.
- Overall, the algorithm runs in O(n*m) time and O(n*m) space.

CODE:
*/


int fmemo(int i, int j, string &s, string &r, vector<vector<int>> &dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == r[j])
        return dp[i][j] = fmemo(i - 1, j - 1, s, r, dp) + 1;
    else
        return dp[i][j] = max(fmemo(i - 1, j, s, r, dp), fmemo(i, j - 1, s, r, dp));
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int lcs = fmemo(n - 1, m - 1, word1, word2, dp);
    return (n + m) - 2 * lcs;
}
