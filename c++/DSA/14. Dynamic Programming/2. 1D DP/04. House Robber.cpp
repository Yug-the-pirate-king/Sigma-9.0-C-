/*
QUESTION:-
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Approach:
1. We can use dynamic programming with memoization to solve this problem.
2. We define a helper function fmemo(i, nums, dp) that calculates the maximum amount of money that can be robbed from the 0th to the ith house using memoization.
3. The function checks if the maximum amount for the ith house is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the maximum amount by considering two options:
   a) Rob the current house and add the money with the maximum amount from the (i-2)th house (since adjacent houses cannot be robbed).
   b) Skip the current house and take the maximum amount from the (i-1)th house.
5. The base case is when i is less than 0, in which case the function returns 0 as there are no houses to rob.
6. In the main function rob(nums), we create a dp array of size n initialized with -1 and call the fmemo function passing n-1 (last house), the nums array, and the dp array as arguments.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating the maximum amount for each house only once and storing it in the dp array.
- The space complexity is also O(n) to store the dp array.
*/

//Memoization
int fmemo(int i, vector<int>& nums, vector<int>& dp) {
    if (i < 0)
        return 0;

    if (i == 0)
        return dp[i] = nums[i];

    if (dp[i] != -1)
        return dp[i];

    int take = nums[i] + fmemo(i - 2, nums, dp);
    int notake = fmemo(i - 1, nums, dp);
    return dp[i] = max(take, notake);
}

//Tabulation
int ftab(int n, vector<int>& nums){
    vector<int> dp(n);
    dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i-2 >= 0) take += dp[i-2];
        int notake = dp[i-1];
        dp[i] = max(take,notake);
    }
    return dp[n-1];
}

//Space Optimization
int fopt(int n, vector<int>& nums){
    int p1 = nums[0], p2 = 0, ans = p1;
    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i-2 >= 0) take += p2;
        int notake = p1;
        ans = max(take,notake);
        p2 = p1; p1 = ans;
    }
    return ans;
}


int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return fmemo(n - 1, nums, dp);
}
