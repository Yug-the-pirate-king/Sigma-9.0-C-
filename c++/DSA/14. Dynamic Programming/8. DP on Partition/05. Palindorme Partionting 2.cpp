/*
QUESTION:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 1D DP array `dp` where dp[i] represents the minimum cuts needed for a palindrome partitioning of s starting from index i.
- Iterate through each index i of the string.
- For each index i, iterate through all possible ending indices j such that j is in the range [i, n).
- Check if the substring from index i to j is a palindrome. If yes, update the dp[i] value by taking the minimum of its current value and dp[j + 1] + 1.
- Finally, return dp[0] - 1, which represents the minimum cuts needed for a palindrome partitioning of the entire string.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the string.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

bool isPalindrome(int i, int j, string& s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int fmemo(int i, string& s, vector<int>& dp){
    if(i == s.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = 1e9;
    for(int j = i; j < s.size(); j++){
        if(isPalindrome(i, j, s)){
            int cost = 1 + fmemo(j + 1, s, dp);
            ans = min(ans, cost);
        }
    }
    return dp[i] = ans;
}

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return fmemo(0, s, dp) - 1;
}
