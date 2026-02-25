/*
QUESTION:
Given an array of positive integers, find the maximum length of a Bitonic subsequence.
A subsequence of an array is called Bitonic if it is first strictly increasing and then strictly decreasing.

APPROACH:
- This problem can be solved using dynamic programming.
- Compute two DP arrays: one from the left and another from the right.
- The left DP array, `left`, represents the length of the longest increasing subsequence ending at index i.
- The right DP array, `right`, represents the length of the longest decreasing subsequence starting at index i.
- Iterate through the array and compute the `left` DP array, considering elements from the left to the right.
- Iterate through the array again and compute the `right` DP array, considering elements from the right to the left.
- The maximum length of the Bitonic subsequence is the maximum sum of the corresponding elements from the `left` and `right` DP arrays minus 1 (to avoid double counting the element at the peak).
- Return the maximum length.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array nums.
- The space complexity is O(n) due to the left and right DP arrays.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

vector<int> fromLeft(int n, vector<int>& nums) {
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i]) {
                dp[i] = max(dp[prev] + 1, dp[i]);
            }
        }
    }
    return dp;
}

vector<int> fromRight(int n, vector<int>& nums) {
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int prev = i + 1; prev < n; prev++) {
            if (nums[prev] < nums[i]) {
                dp[i] = max(dp[prev] + 1, dp[i]);
            }
        }
    }
    return dp;
}

int LongestBitonicSequence(vector<int> nums) {
    int n = nums.size();
    vector<int> left = fromLeft(n, nums);
    vector<int> right = fromRight(n, nums);
    
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i] + right[i] - 1);
    }
    
    return ans;
}
