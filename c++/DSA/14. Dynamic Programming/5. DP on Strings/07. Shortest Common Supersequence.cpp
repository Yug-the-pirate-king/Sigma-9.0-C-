/*
QUESTION:
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.

APPROACH:
- This problem can be solved using dynamic programming to find the length of the shortest common supersequence (SCS).
- The SCS is the shortest string that contains both str1 and str2 as subsequences.
- The idea is to first find the length of the SCS using a dynamic programming approach.
- Once the length is found, we can construct the SCS using the dp array and backtracking.
- We start from the last cell of the dp array and move either diagonally (when characters match) or towards the direction with the greater value.
- During backtracking, we append the characters from str1 or str2 to the SCS string based on the movement direction.

COMPLEXITY ANALYSIS:
- The time complexity of finding the length of the SCS is O(n*m), where n and m are the lengths of the two strings.
- The space complexity is O(n*m) due to the dp array.
- The backtracking process takes O(n + m) time.
- Overall, the algorithm runs in O(n*m) time and O(n*m) space.

CODE:
*/

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    string scs = "";
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            scs = str1[i - 1] + scs;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                scs = str1[i - 1] + scs;
                i--;
            } else {
                scs = str2[j - 1] + scs;
                j--;
            }
        }
    }
    while (i > 0) {
        scs = str1[i - 1] + scs;
        i--;
    }
    while (j > 0) {
        scs = str2[j - 1] + scs;
        j--;
    }
    return scs;
}
