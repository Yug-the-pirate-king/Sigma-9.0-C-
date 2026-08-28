#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

pair<int, int> findMinMax(const int* nums, int n) {
    if (n <= 0) {
        return {0, 0};
    }
    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return {minVal, maxVal};
}

void printArray(const int* nums, int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void counting_sort(int* nums, int n) {
    if (n <= 0) {
        return;
    }

    pair<int, int> bounds = findMinMax(nums, n);
    int minVal = bounds.first;
    int maxVal = bounds.second;

    long long range = static_cast<long long>(maxVal) - static_cast<long long>(minVal) + 1;
    vector<int> freq(static_cast<size_t>(range), 0);

    for (int i = 0; i < n; ++i) {
        ++freq[nums[i] - minVal];
    }

    for (int i = minVal, j = 0; i <= maxVal; ++i) {
        int idx = i - minVal;
        while (freq[idx] > 0) {
            nums[j++] = i;
            --freq[idx];
        }
    }

    printArray(nums, n);
}

int main() {
    int nums[] = {1, 4, 1, 3, 2, 4, 3, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    counting_sort(nums, n);
    return 0;
}