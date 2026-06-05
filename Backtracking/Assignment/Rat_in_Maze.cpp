#include <iostream>
#include <vector>
#include <string>
using namespace std;

void rat(vector<vector<int>> &maze, int row, int col, int r, int c, string ans)
{
    if (r == row - 1 && c == col - 1)
    {
        cout << ans << "\n";
        return;
    }
    if (r >= row || c >= col)
    {
        return;
    }
    if (c + 1 < col)
    {
        if (maze[r][c + 1] != 0)
        {
            ans.push_back('R');
            rat(maze, row, col, r, c + 1, ans);
            ans.pop_back();
        }
    }
    if (r + 1 < row)
    {
        if (maze[r + 1][c] != 0)
        {
            ans.push_back('D');
            rat(maze, row, col, r + 1, c, ans);
        }
    }

    return;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    rat(maze, 4, 4, 0, 0, "");

    return 0;
}