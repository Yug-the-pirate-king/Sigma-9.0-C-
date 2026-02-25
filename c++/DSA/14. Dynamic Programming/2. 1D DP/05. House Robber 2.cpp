/*
QUESTION:-
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Approach:
1. Since the houses are arranged in a circle, the robber cannot rob the first and last house together as they are adjacent.
2. To solve this problem, we can divide it into two subproblems: one where the robber robs from the first house to the second-last house (excluding the last house), and another where the robber robs from the second house to the last house (excluding the first house).
3. We can use dynamic programming with memoization to calculate the maximum amount of money that can be robbed in each subproblem.
4. We define a helper function fmemo(e, i, nums, dp) that calculates the maximum amount of money that can be robbed from the e-th to the i-th house using memoization.
5. The function checks if the maximum amount for the i-th house is already calculated and stored in the dp array. If yes, it returns the value from dp.
6. Otherwise, it calculates the maximum amount by considering two options:
   a) Rob the current house and add the money with the maximum amount from the (i-2)th house (since adjacent houses cannot be robbed).
   b) Skip the current house and take the maximum amount from the (i-1)th house.
7. The base case is when i is less than e, in which case the function returns 0 as there are no houses to rob.
8. In the main function rob(nums), we first check if there is only one house. If yes, the robber can only rob that house, so we return the amount in that case.
9. Otherwise, we create a dp array of size n initialized with -1 and call the fmemo function twice: one for robbing from the first to the second-last house and the other for robbing from the second to the last house.
10. Finally, we return the maximum amount from the two subproblems, which gives the maximum amount the robber can rob without alerting the police.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating the maximum amount for each house only once and storing it in the dp array.
- The space complexity is also O(n) to store the dp array.
*/

// Memoization
int fmemo(int e, int i, vector<int>& nums, vector<int>& dp) {
    if (i < e)
        return 0;

    if (i == e)
        return dp[i] = nums[i];

    if (dp[i] != -1)
        return dp[i];

    int take = nums[i] + fmemo(e, i - 2, nums, dp);
    int notake = fmemo(e, i - 1, nums, dp);
    return dp[i] = max(take, notake);
}

// Tabulation
int ftab(int e, int n, vector<int>& nums){
    vector<int> dp(n);
    dp[e] = nums[e];
    for(int i=e+1; i<n-(!e); i++){
        int take = nums[i];
        if(i-2>=e)
            take += dp[i-2];
        int notake = dp[i-1];
        dp[i] = max(take,notake);
    }
    return dp[n-1-(!e)];
}

// Space Optimization
int fopt(int e, int n, vector<int>& nums){
    int p1 = nums[e], p2 = 0, ans = 0;
    for(int i=e+1; i<n-(!e); i++){
        int take = nums[i];
        if(i-2>=e)
            take += p2;
        int notake = p1;
        ans = max(take,notake);
        p2 = p1; p1 = ans;
    }
    return ans;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> dp(n, -1);
    int s = fmemo(1, n - 1, nums, dp); // Rob from 1st to 2nd-last house
    dp.assign(n, -1);
    int e = fmemo(0, n - 2, nums, dp); // Rob from 2nd to last house
    return max(s, e);
}
