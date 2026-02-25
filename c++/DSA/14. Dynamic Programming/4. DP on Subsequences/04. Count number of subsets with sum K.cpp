/*
QUESTION:
Given an array arr[] of non-negative integers and an integer sum, 
the task is to count all subsets of the given array with a sum 
equal to a given sum.

Note: Answer can be very large, so, output answer modulo 10^9+7

Example 1:
Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

APPROACH:
- We'll use a bottom-up dynamic programming approach using a 2D dp array.
- Initialize dp[i][j] as the number of subsets with sum 'j' using the first 'i' elements.
- Base cases:
  - dp[0][0] = 1 since an empty subset has a sum of 0.
  - dp[i][0] = 1 since there's always an empty subset.
- For each element 'arr[i]' and each possible sum 'j' from 1 to 'sum':
  - dp[i][j] = dp[i-1][j] (not taking the current element)
  - if 'arr[i]' is less than or equal to 'j', then dp[i][j] += dp[i-1][j-arr[i]] (taking the current element)
- Return dp[n][sum] which represents the number of subsets with sum 'sum' using all 'n' elements.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n * sum), where 'n' is the number of elements and 'sum' is the required sum.
- The space complexity is O(n * sum) for the dp array.

CODE:
*/


const int mod = 1e9 + 7;

// Memoization
int fmemo(int i, int tar, int arr[], vector<vector<int>>& dp){
    if(i == 0){
        if(tar == 0 && arr[i] == 0) return dp[i][tar] = 2;
        if(tar == 0) return dp[i][tar] = 1;
        return dp[i][tar] = (arr[i] == tar);
    }

    if(dp[i][tar] != -1) return dp[i][tar];

    int take = 0;
    if(arr[i] <= tar) take = fmemo(i - 1, tar - arr[i], arr, dp);
    int notake = fmemo(i - 1, tar, arr, dp);
    return dp[i][tar] = (take + notake) % mod;
}

// Tabulation
int ftab(int n, int sum, int arr[]){
    vector<vector<int>> dp(n,vector<int>(sum+1));
    for(int i=0; i<n; i++){
        for(int tar=0; tar<=sum; tar++){
            if(i==0){
                if(tar==0 && arr[i]==0) dp[i][tar] = 2;
                else if(tar==0) dp[i][tar] = 1;
                else dp[i][tar] =  (arr[i]==tar);
                continue;
            }
            int take = 0;
            if(arr[i] <= tar) take = dp[i-1][tar-arr[i]];
            int notake = dp[i-1][tar];
            dp[i][tar] =  (take+notake)%mod;
        }
    }
    return dp[n-1][sum];
}

// Space Optimization
int fopt(int n, int sum, int arr[]){
    vector<int> prev(sum+1);
    for(int i=0; i<n; i++){
        vector<int> curr(sum+1);
        for(int tar=0; tar<=sum; tar++){
            if(i==0){
                if(tar==0 && arr[i]==0) curr[tar] = 2;
                else if(tar==0) curr[tar] = 1;
                else curr[tar] =  (arr[i]==tar);
                continue;
            }
            int take = 0;
            if(arr[i] <= tar) take = prev[tar-arr[i]];
            int notake = prev[tar];
            curr[tar] =  (take+notake)%mod;
        }
        prev = curr;
    }
    return prev[sum];
}

int perfectSum(int arr[], int n, int sum){
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return fmemo(n - 1, sum, arr, dp);
}
