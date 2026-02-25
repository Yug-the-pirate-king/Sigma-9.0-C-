/*
QUESTION:
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example:
Input: arr = [1, 15, 7, 9, 2, 5, 10], k = 3
Output: 84
Explanation: arr becomes [15, 15, 15, 9, 10, 10, 10]

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 1D DP array `dp` where dp[i] represents the largest sum of the array after partitioning from index i to the end.
- Iterate through each index i of the array in reverse order.
- For each index i, iterate through all possible partition lengths from 1 to k.
- Calculate the maximum sum for the current partition, which is the maximum element within the partition multiplied by the length of the partition.
- Update dp[i] with the maximum value among all possible partition scenarios.
- Finally, return dp[0], which represents the largest sum of the array after partitioning.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n * k), where n is the length of the array.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n * k) time and O(n) space.

CODE:
*/

int fmemo(int i, int k, vector<int>& arr, vector<int>& dp){
    if(i == arr.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int n = arr.size();
    int maxi = 0, ans = 0;
    for(int j = i; j < min(i + k, n); j++){
        maxi = max(maxi, arr[j]);
        int maxSum = maxi * (j - i + 1) + fmemo(j + 1, k, arr, dp);
        ans = max(ans, maxSum);
    }
    return dp[i] = ans;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return fmemo(0, k, arr, dp);
}
