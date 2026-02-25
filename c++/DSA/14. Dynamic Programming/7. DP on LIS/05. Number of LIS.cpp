/*
QUESTION:
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

APPROACH:
- This problem can be solved using dynamic programming.
- Compute two DP arrays: one for the length of the longest increasing subsequence ending at index i (`dp`) and another for the count of such subsequences (`cnt`).
- Iterate through the array and for each index i, iterate through all previous indices (prev) from 0 to i-1.
- If nums[prev] < nums[i], update the `dp` and `cnt` arrays accordingly.
- Find the maximum value in the `dp` array to get the length of the longest increasing subsequence (`lis`).
- Iterate through the `dp` array again and count the number of subsequences that have the length equal to `lis`.
- Return the total count of such subsequences.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array nums.
- The space complexity is O(n) due to the dp and cnt arrays.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

int ftab(int n, vector<int>& nums) {
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i]) {
                if (dp[i] == dp[prev] + 1) {
                    cnt[i] += cnt[prev];
                } else if (dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
            }
        }
    }
    
    int lis = *max_element(dp.begin(), dp.end());
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == lis) {
            ans += cnt[i];
        }
    }
    
    return ans;
}

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    return ftab(n, nums);
}
