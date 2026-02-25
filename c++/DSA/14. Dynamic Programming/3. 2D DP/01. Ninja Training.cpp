/*
QUESTION:-
Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

Example:
Input:
n = 3
points = [[1,2,5],[3,1,1],[3,3,3]]
Output:
11
Explanation:
Geek will learn a new move and earn 5 points on the first day,
then on the second day, he will do running and earn 3 points,
and on the third day, he will do fighting and earn 3 points.
So, the maximum points is 11.

Approach:
1. To maximize the merit points, we need to find the maximum sum of points such that the Geek can't perform the same activity on two consecutive days.
2. We can solve this problem using dynamic programming with memoization (top-down approach).
3. We define a helper function fmemo(n, prev, points, memo) that calculates the maximum points the Geek can earn from the nth day onwards, given that on the (n-1)th day, he performed the activity indexed by 'prev'.
4. The function checks if the maximum points for the (n-1)th day and 'prev' activity is already calculated and stored in the memo array. If yes, it returns the value from memo.
5. Otherwise, it calculates the maximum points for the nth day by considering all three activities except the one performed on the (n-1)th day. It then adds the points for the nth day and recursively calls the function for the (n-1)th day with the new activity and updates the maximum points.
6. The base case is when n is less than 0, in which case the function returns 0 as there are no days to earn points.
7. In the main function maximumPoints(points, n), we create a dp (memo) array of size n initialized with -1 and call the fmemo function for the nth day with the initial activity as -1 (since no activity is performed on the first day).
8. Finally, we return the maximum points obtained for all three possible starting activities (running, fighting, learning practice) as the result.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating the maximum points for each day only once and storing it in the memo array.
- The space complexity is also O(n) to store the memo array.

*/

//Memoization
int fmemo(int n, int prev, vector<vector<int>>& points, vector<vector<int>>& memo) {
    if (n < 0)
        return 0;

    if (prev != -1 && memo[n][prev] != -1) {
        return memo[n][prev];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (i != prev) {
            int temp = points[n][i] + fmemo(n - 1, i, points, memo);
            ans = max(ans, temp);
        }
    }

    if (prev != -1) {
        memo[n][prev] = ans;
    }

    return ans;
}

//Tbaulation
int ftab(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: for the first row, the maximum points for each column are the points in that row.
    for (int i = 0; i < 3; i++) {
        dp[0][i] = points[0][i];
    }

    // Calculate the maximum points for each row while considering the previous row's choices.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], points[i][j] + dp[i - 1][k]);
                }
            }
        }
    }

    // Find the maximum points among all choices for the last row.
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

    return ans;
}

int maximumPoints(vector<vector<int>>& points, int n) {
    vector<vector<int>> memo(n, vector<int>(3, -1));
    return fmemo(n - 1, -1, points, memo);
}
