/*
QUESTION:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

APPROACH:
- This problem can be solved using dynamic programming.
- Let dp[i] represent the length of the longest increasing subsequence ending at index i.
- For each element at index i, we iterate through all the previous indices (prev) from 0 to i-1.
- If nums[prev] is smaller than nums[i], it means we can extend the increasing subsequence ending at prev by including nums[i].
- We update dp[i] as max(dp[prev] + 1, dp[i]).
- Initialize a variable ans to keep track of the maximum value in dp.
- Return ans as the length of the longest increasing subsequence.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array nums.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

int ftab(int n, vector<int>& nums) {
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i]) {
                dp[i] = max(dp[prev] + 1, dp[i]);
            }
        }
    }
    int ans = -1;
    for (auto i : dp) ans = max(ans, i);
    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return ftab(n, nums);
}
