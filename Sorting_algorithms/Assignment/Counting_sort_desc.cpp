#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void counting_sort(int *nums, int n) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }

    int range = maxVal - minVal + 1;
    int *freq = new int[range]();
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[nums[i] - minVal]++;
    }

    // Fill nums[] in descending order
    int idx = 0;
    for (int i = range - 1; i >= 0; i--) {
        while (freq[i] > 0) {
            nums[idx++] = i + minVal;
            freq[i]--;
        }
    }

    delete[] freq;

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {3,6,2,1,8,7,4,5,3,1};
    int n = sizeof(nums) / sizeof(int);
    counting_sort(nums, n);
    return 0;
}