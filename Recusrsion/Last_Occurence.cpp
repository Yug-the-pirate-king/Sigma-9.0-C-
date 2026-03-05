#include "../myheaders.h"
using namespace std;

int Last_Occurence(vector<int> &arr, int i, int target)
{

    if (i == arr.size())
    {
        return -1;
    }

    int index = Last_Occurence(arr, i + 1, target);

    if (index == -1)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4};
    cout << Last_Occurence(arr, 0, 3);
    return 0;
}