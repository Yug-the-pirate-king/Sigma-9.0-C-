/*
QUESTION:

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal, or `false` otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

APPROACH:

- To solve this problem, we can use dynamic programming.
- We'll create a 2D DP array where `dp[i][j]` represents whether it's possible to select a subset from the first `i` elements of the `nums` array that sums up to `j`.
- The base case is when `j` is 0, in which case it's always possible to select an empty subset.
- For each element in the `nums` array, we have two choices: include it in the subset or exclude it.
- So, the recurrence relation becomes:
  dp[i][j] = dp[i - 1][j] (exclude nums[i]) || dp[i - 1][j - nums[i]] (include nums[i])

COMPLEXITY ANALYSIS:

- The time complexity of this approach is O(n * sum), where `n` is the number of elements in the `nums` array and `sum` is the sum of all elements.

CODE:
*/
// Memoization
bool fmemo(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    if (sum == 0)
        return true;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (i == 0)
        return dp[i][sum] = (sum == arr[i]);

    bool t = false;
    if (arr[i] <= sum)
        t = fmemo(i - 1, sum - arr[i], arr, dp);

    bool nt = fmemo(i - 1, sum, arr, dp);

    return dp[i][sum] = (t || nt);
}

// Tabulation
bool ftab(int n, int tar, vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(tar+1));
    for(int i=0; i<n; i++){
        for(int sum=0; sum<=tar; sum++){
            if(sum==0){
                dp[i][sum] = true;
                continue;
            }
            if(i==0){
                dp[i][sum] = (sum==arr[i]);
                continue;
            }
            bool t = false;
            if(arr[i] <= sum) t = dp[i-1][sum-arr[i]];
            bool nt = dp[i-1][sum];
            dp[i][sum] = (t || nt);
        }
    }
    return dp[n-1][tar];
}

// Space Optimization
bool fopt(int n, int tar, vector<int>& arr){
    vector<int> prev(tar+1);
    for(int i=0; i<n; i++){
        vector<int> curr(tar+1);
        for(int sum=0; sum<=tar; sum++){
            if(sum==0){
                curr[sum] = true;
                continue;
            }
            if(i==0){
                curr[sum] = (sum==arr[i]);
                continue;
            }
            bool t = false;
            if(arr[i] <= sum) t = prev[sum-arr[i]];
            bool nt = prev[sum];
            curr[sum] = (t || nt);
        }
        prev = curr;
    }
    return prev[tar];
}

bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for(auto i:nums) sum+=i;
    if(sum%2!=0) return false;
    int k = sum/2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return fmemo(n-1,k,nums,dp);
}
