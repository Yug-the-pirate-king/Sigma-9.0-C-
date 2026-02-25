/*
QUESTION:
Given an array 'nums' and an integer 'target', the task is to count 
the number of ways to make the sum of elements of one subset equal 
to 'target'.

Example:
Input: nums = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation: There are 5 ways to achieve the target sum: 
{1, 1, 1}, {1, 2}, {2, 1}, {1, 2}, {3}

APPROACH:
- The problem can be reduced to finding the count of subsets with a 
  given sum.
- Initialize dp[i][j] as the number of subsets with sum 'j' using 
  the first 'i' elements.
- Base cases:
  - dp[0][0] = 1 since an empty subset has a sum of 0.
  - dp[i][0] = 1 since there's always an empty subset.
- For each element 'nums[i]' and each possible sum 'j' from 1 to 'target':
  - dp[i][j] = dp[i-1][j] (not taking the current element)
  - if 'nums[i]' is less than or equal to 'j', then dp[i][j] += dp[i-1][j-nums[i]] (taking the current element)
- The required answer will be dp[n][target] where 'n' is the number 
  of elements in the array.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n * target), where 'n' 
  is the number of elements in the array.
- The space complexity is O(n * target) for the dp array.

CODE:
*/


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
    return dp[i][tar] = (take + notake);
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
            dp[i][tar] =  (take+notake);
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
            curr[tar] =  (take+notake);
        }
        prev = curr;
    }
    return prev[sum];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size(), sum = 0; 
    for(auto i:nums) sum += i;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return fmemo(n - 1, target, nums, dp);
}
