#include <iostream>
using namespace std;

void binary_search(int nums[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (nums[mid] == key) {
            cout << "Found at index: " << mid << endl;
            return; // exit after finding
        }
        else if (nums[mid] > key) {
            end = mid - 1; // move left
        }
        else {
            start = mid + 1; // move right
        }
    }
    cout << "Not Found" << endl;
}

int main() {
    int nums[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(nums) / sizeof(int);
    int key = 12;

    binary_search(nums, n, key);
    return 0;
}
