#include "../myheaders.h"

void merge(vector<int> &arr, int si, int mid, int ei)
{
    vector<int> temp;
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

void merge_sort(vector<int> &arr, int si, int ei)
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

void printArr(vector<int> arr)
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
    vector<int> arr = {6, 3, 7, 5, 2, 4};

    merge_sort(arr, 0, arr.size() - 1);

    printArr(arr);
    return 0;
}