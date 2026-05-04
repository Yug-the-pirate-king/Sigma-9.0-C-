#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int> &arr, int si, int mid, int ei) {
    int i = si, j = mid + 1;
    int invCount = 0;
    vector<int> temp;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= ei) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[si + k] = temp[k];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int si, int ei) {
    if (si >= ei) return 0;

    int mid = si + (ei - si) / 2;

    int invCount = 0;
    invCount += mergeSort(arr, si, mid);
    invCount += mergeSort(arr, mid + 1, ei);
    invCount += mergeAndCount(arr, si, mid, ei);

    return invCount;
}

int getInversion(vector<int> &arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "InversionCount = " << getInversion(arr, arr.size());
}