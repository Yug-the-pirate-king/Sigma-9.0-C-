/*
QUESTION:
Given an array arr of size n containing non-negative integers,
the task is to divide it into two sets S1 and S2 such that the absolute
difference between their sums is minimum and find the minimum difference

Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

APPROACH:
- Calculate the sum of all elements in the array.
- Initialize a 2D dp array of size n x (sum + 1) to store if it is possible to achieve a sum 's' using the first 'i' elements.
- Initialize dp[i][0] to true, since an empty subset can have a sum of 0.
- For each element 'arr[i]' and each possible sum 's' from 1 to 'sum':
  - Check if it's possible to achieve a sum of 's' using the first 'i-1' elements, or using 's - arr[i]' and the first 'i-1' elements.
  - Update dp[i][s] accordingly.
- Iterate through the dp array for the last row and find the minimum absolute difference between the sum 's' and 'totalSum - s' for which dp[n-1][s] is true.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n * sum), where 'n' is the number of elements and 'sum' is the sum of all elements.
- The space complexity is O(n * sum) for the dp array.

CODE:
*/


bool ftab(int n, int tar, int arr[], vector<vector<int>>& dp){
    for(int i = 0; i < n; i++){
        for(int sum = 0; sum <= tar; sum++){
            if(sum == 0){
                dp[i][sum] = true;
                continue;
            }
            if(i == 0){
                dp[i][sum] = (sum == arr[i]);
                continue;
            }
            bool t = false;
            if(arr[i] <= sum) t = dp[i-1][sum - arr[i]];
            bool nt = dp[i-1][sum];
            dp[i][sum] = (t || nt);
        }
    }
    return dp[n-1][tar];
}

int minDifference(int arr[], int n){
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];
    vector<vector<int>> dp(n, vector<int>(totalSum + 1));
    ftab(n, totalSum, arr, dp);
    int ans = INT_MAX;
    for(int i = 0; i <= totalSum; i++){
        if(dp[n-1][i])
            ans = min(ans, abs(i - (totalSum - i)));
    }
    return ans;
}
