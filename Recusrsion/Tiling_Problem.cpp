#include "../myheaders.h"
using namespace std;

int countTilingWays(int boardWidth)
{
    if (boardWidth == 0 || boardWidth == 1)
    {
        return 1;
    }

    int verticalTilings = countTilingWays(boardWidth - 1);
    int horizontalTilings = countTilingWays(boardWidth - 2);

    return verticalTilings + horizontalTilings;
}

int main()
{
    int boardWidth = 5;
    cout << countTilingWays(boardWidth);
    return 0;
}