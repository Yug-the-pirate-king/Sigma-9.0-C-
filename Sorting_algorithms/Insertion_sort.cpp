#include <iostream>
using namespace std;

void insertion_sort(int *nums, int size) {
    for (int i = 1; i < size; i++) {   // start from index 1
        int curr = nums[i];
        int prev = i - 1;

        // Shift elements greater than curr to the right
        while (prev >= 0 && nums[prev] > curr) {
            nums[prev + 1] = nums[prev];
            prev--;
        }

        nums[prev + 1] = curr;  // place curr at correct position
    }

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {5, 4, 1, 2, 3};
    int size = sizeof(nums) / sizeof(int);

    insertion_sort(nums, size);
    return 0;
}
