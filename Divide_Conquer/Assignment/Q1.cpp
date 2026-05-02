#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void merge(vector<string> &arr, int si, int mid, int ei)
{
    vector<string> temp;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i += 1;
        }
        else
        {
            temp.push_back(arr[j]);
            j += 1;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i += 1;
    }

    while (j <= ei)
    {
        temp.push_back(arr[j]);
        j += 1;
    }

    for (int idx = si, x = 0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }

    return;
}

void merge_sort(vector<string> &arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;

    merge_sort(arr, si, mid);     // left
    merge_sort(arr, mid + 1, ei); // right

    merge(arr, si, mid, ei);
}

void printArr(vector<string> arr)
{
    int n = arr.size();
    cout << "The arr is :\n";
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<string> arr = {"sun", "earth", "mars", "mercury"};

    merge_sort(arr, 0, arr.size() - 1);

    printArr(arr);
    return 0;
}