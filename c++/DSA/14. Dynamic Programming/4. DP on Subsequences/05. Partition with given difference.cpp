/*
QUESTION:
Given an array arr, partition it into two subsets(possibly empty) 
such that their union is the original array. Let the sum of the 
elements of these two subsets be S1 and S2. 

Given a difference d, count the number of partitions in which S1 is 
greater than or equal to S2 and the difference S1 and S2 is equal to d. 
Since the answer may be large, return it modulo 10^9 + 7.

Example 1:
Input:
n = 4, d = 3
arr[] = {5, 2, 6, 4}
Output: 1
Explanation:
There is only one possible partition of this array. 
Partition: {6, 4}, {5, 2}. The subset difference between subset sums is: (6 + 4) - (5 + 2) = 3.

APPROACH:
- We'll use a similar approach as used in the subset sum count problem.
- Initialize dp[i][j] as the number of subsets with sum 'j' using the first 'i' elements.
- Base cases:
  - dp[0][0] = 1 since an empty subset has a sum of 0.
  - dp[i][0] = 1 since there's always an empty subset.
- For each element 'arr[i]' and each possible sum 'j' from 1 to 'sum':
  - dp[i][j] = dp[i-1][j] (not taking the current element)
  - if 'arr[i]' is less than or equal to 'j', then dp[i][j] += dp[i-1][j-arr[i]] (taking the current element)
- Initialize 'ans' as 0.
- For each possible subset sum 'i':
  - Check if the difference between (i - (sum - i)) is equal to 'd'.
  - If it is, add the result of fmemo(n, i, arr, dp) to 'ans'.
- Return 'ans' % mod which represents the answer.

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

int countPartitions(int n, int d, vector<int>& arr) {
    int sum = 0, ans = 0;
    for(auto i:arr) sum += i;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    for(int i = 0; i <= sum; i++){
        if(i - (sum - i) == d)
            ans = (ans + fmemo(n - 1, i, arr, dp)) % mod;
    }
    return ans;
}
