/*
QUESTION:
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
- answer[i] % answer[j] == 0, or
- answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

APPROACH:
- This problem can be solved using dynamic programming.
- Sort the input array nums in ascending order.
- Let dp[i] represent the size of the largest divisible subset ending at index i.
- Additionally, maintain a prevmap to track the previous index in the subset.
- Iterate through the sorted array and for each index i, iterate through all previous indices (prev) from 0 to i-1.
- If nums[i] is divisible by nums[prev] and dp[i] < dp[prev] + 1, update dp[i] and prevmap[i].
- Find the index i where dp has the maximum value.
- Construct the largest divisible subset using the prevmap and the found index i.
- Return the subset.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array nums.
- The space complexity is O(n) due to the dp and prevmap arrays, as well as the lis vector.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

vector<int> ftab(int n, vector<int>& nums) {
    vector<int> dp(n, 1);
    vector<int> prevmap(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                dp[i] = dp[prev] + 1;
                prevmap[i] = prev;
            }
        }
    }
    
    int i = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    
    while (i >= 0) {
        lis.push_back(nums[i]);
        i = prevmap[i];
    }
    
    return lis;
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return ftab(n, nums);
}
