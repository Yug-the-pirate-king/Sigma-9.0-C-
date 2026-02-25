/*
QUESTION:

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Example:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

CODE:
*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans(image.begin(), image.end());
    int m = image.size(), n = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int s = ans[sr][sc];
    ans[sr][sc] = color;

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == s && ans[nx][ny] != color) {
                    ans[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
    }

    return ans;
}
