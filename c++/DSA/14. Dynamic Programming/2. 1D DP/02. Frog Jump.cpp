/*
QUESTION:-
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time, the Geek can climb either one or two steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]), where abs() means the absolute difference.
Return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

Approach:
1. We can use dynamic programming with memoization to find the minimum energy required to jump from the 0th stair to the (n-1)th stair.
2. We define a helper function fmemo(i, h, dp) that calculates the minimum energy required to jump from the 0th stair to the ith stair using memoization.
3. The function checks if the minimum energy for the ith stair is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the minimum energy by taking two possible jumps - either from (i-1)th stair or from (i-2)th stair - and stores the result in dp[i].
5. The base case is when i is 0, in which case the function returns 0 as the Geek is already at the 0th stair.
6. In the main function minimumEnergy(height, n), we create a dp array of size n initialized with -1 and call the fmemo function passing n-1 (last stair), the height array, and the dp array as arguments.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating and storing the minimum energy for each stair.
- The space complexity is also O(n) to store the dp array.
*/

// Memoization
int fmemo(int i, vector<int>& h, vector<int>& dp) {
    if (i == 0)
        return dp[i] = 0;

    if (dp[i] != -1)
        return dp[i];

    int s1 = INT_MAX, s2 = INT_MAX;
    if (i - 1 >= 0)
        s1 = fmemo(i - 1, h, dp) + abs(h[i - 1] - h[i]);
    if (i - 2 >= 0)
        s2 = fmemo(i - 2, h, dp) + abs(h[i - 2] - h[i]);

    return dp[i] = min(s1, s2);
}

// Tabulation
int ftab(int n, vector<int>& h){
    vector<int> dp(n);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int s1 = INT_MAX, s2 = INT_MAX;
        if(i-1>=0) s1 = dp[i-1]+abs(h[i-1]-h[i]);
        if(i-2>=0) s2 = dp[i-2]+abs(h[i-2]-h[i]);
        dp[i] = min(s1,s2);
    }
    return dp[n-1];
}

// Space Optimized
int fopt(int n, vector<int>& h){
    int p1 = 0, p2 = 0, ans = 0;
    for(int i=1; i<n; i++){
        int s1 = INT_MAX, s2 = INT_MAX;
        if(i-1>=0) s1 = p1+abs(h[i-1]-h[i]);
        if(i-2>=0) s2 = p2+abs(h[i-2]-h[i]);
        ans = min(s1,s2);
        p2 = p1; p1 = ans;
    }
    return ans;
}

int minimumEnergy(vector<int>& height, int n) {
    return fopt(n, height);
}

