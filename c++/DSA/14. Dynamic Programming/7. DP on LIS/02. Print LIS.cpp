/*
QUESTION:
Given an integer n and an array of integers, return the Longest Increasing Subsequence which is lexicographically smallest corresponding to the indices of the elements.

APPROACH:
- This problem can be solved using dynamic programming.
- Let dp[i] represent the length of the longest increasing subsequence ending at index i.
- Additionally, maintain a prevmap to track the previous index in the increasing subsequence.
- Iterate through the array and for each index i, iterate through all previous indices (prev) from 0 to i-1.
- If arr[prev] < arr[i] and dp[i] < dp[prev] + 1, update dp[i] and prevmap[i].
- Find the index i where dp has the maximum value.
- Construct the Longest Increasing Subsequence using the prevmap and the found index i.
- Return the LIS in reverse order to get the lexicographically smallest sequence.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array arr.
- The space complexity is O(n) due to the dp and prevmap arrays, as well as the lis vector.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

vector<int> ftab(int n, vector<int>& arr) {
    vector<int> dp(n, 1);
    vector<int> prevmap(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[prev] < arr[i] && dp[i] < dp[prev] + 1) {
                dp[i] = dp[prev] + 1;
                prevmap[i] = prev;
            }
        }
    }
    
    int i = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    
    while (i >= 0) {
        lis.push_back(arr[i]);
        i = prevmap[i];
    }
    
    reverse(lis.begin(), lis.end());
    return lis;
}

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    return ftab(n, arr);
}
