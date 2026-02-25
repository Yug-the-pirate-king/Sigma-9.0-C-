/*
QUESTION:-
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Example:
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.

Approach:
1. We can solve this problem using dynamic programming with memoization (top-down approach).
2. We define a helper function fmemo(i, sum, arr, dp) that checks if there is a subset of elements up to index i whose sum is equal to the given sum.
3. The function checks if the target sum is 0. If yes, it means we have found a subset with the given sum and returns true.
4. If i is 0, it means we are at the first element, so the function checks if the first element is equal to the target sum.
5. If the dp value for the current index and sum is already calculated, it returns the stored value.
6. If the current element (arr[i]) is less than or equal to the target sum, the function recursively checks for two cases: including the current element in the subset (by reducing the sum) or excluding it (by not changing the sum).
7. If any of the above cases returns true, the dp value for the current index and sum is updated to true.
8. Finally, we return the dp value for the last index and the given sum.

Complexity Analysis:
- The time complexity of the fmemo function is O(n * sum), where n is the number of elements in the array and sum is the target sum. This is because the function calculates the result for each index and sum only once and stores it in the dp array.
- The space complexity is also O(n * sum) to store the dp array.

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

bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return fmemo(n - 1, sum, arr, dp);
}
