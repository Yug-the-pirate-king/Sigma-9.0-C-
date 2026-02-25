/*QUESTION:

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

APPROACH:
- We can use Dijkstra's algorithm to find the minimum effort path from the top-left cell to the bottom-right cell.
- We will maintain a priority queue to keep track of cells with the minimum effort needed.
- Start from the top-left cell with effort 0 and explore neighboring cells in all four directions.
- Calculate the effort required to move to a neighboring cell and update the effort if it is lower than the current value.
- Continue this process until we reach the bottom-right cell.

COMPLEXITY ANALYSIS:
- Since we are using Dijkstra's algorithm, the time complexity is O((N*M) * log(N*M)), where N is the number of rows and M is the number of columns in the 2D array.
- The space complexity is O(N*M) to store the distance values.

CODE:
*/

typedef pair<int, pair<int, int>> tri;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    priority_queue<tri, vector<tri>, greater<tri>> pq;
    dis[0][0] = 0;
    pq.push({0, {0, 0}});

    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    int ans = INT_MIN;
    while (!pq.empty()) {
        tri t = pq.top();
        pq.pop();
        int x = t.second.first, y = t.second.second;
        ans = max(ans, t.first);
        if (x == n - 1 && y == m - 1) return ans;
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (dis[nx][ny] > abs(heights[x][y] - heights[nx][ny]))) {
                dis[nx][ny] = abs(heights[x][y] - heights[nx][ny]);
                pq.push({dis[nx][ny], {nx, ny}});
            }
        }
    }
    return -1; // If the bottom-right cell cannot be reached
}
