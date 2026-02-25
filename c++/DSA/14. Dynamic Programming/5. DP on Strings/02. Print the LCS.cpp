/*
QUESTION:
Print the Longest Common Subsequence between two strings.

APPROACH:
- We will use dynamic programming to find the longest common subsequence (LCS) between two strings.
- We will create a 2D array 'dp' of size (n+1) x (m+1), where n is the length of the first string and m is the length of the second string.
- dp[i][j] will store the length of LCS between the first i characters of string s1 and the first j characters of string s2.
- We will iterate through the strings and fill up the dp array as follows:
  - If s1[i-1] matches s2[j-1], then dp[i][j] = dp[i-1][j-1] + 1, as we are extending the LCS by one character.
  - Otherwise, dp[i][j] = max(dp[i-1][j], dp[i][j-1]), taking the maximum length LCS till the previous characters.
- Once the dp array is filled, we will backtrack from the bottom-right corner (dp[n][m]) to reconstruct the LCS.
- We will start from dp[n][m] and go to dp[0][0], following the conditions mentioned above. If s1[i-1] matches s2[j-1], we add that character to the LCS.
- Finally, we reverse the obtained LCS to get the correct order.

COMPLEXITY ANALYSIS:
- The time complexity of the dynamic programming part is O(n * m), where n is the length of the first string and m is the length of the second string.
- The space complexity is also O(n * m) due to the dp array.
- The space required for storing the LCS is O(min(n, m)), which is the maximum length of the LCS.
- Overall, the algorithm runs in O(n * m) time and O(n * m) space.

CODE:
*/


void ftab(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

string findLCS(int n, int m, string &s1, string &s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    ftab(n, m, s1, s2, dp);
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i = i - 1;
            j = j - 1;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i = i - 1;
            else
                j = j - 1;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}
