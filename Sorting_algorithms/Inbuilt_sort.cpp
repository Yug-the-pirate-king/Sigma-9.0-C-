#include <iostream>
#include<algorithm>
using namespace std;

void sorter(int *nums, int n){

    // sort(nums,nums+n); // Ascending

    sort(nums,nums+n,greater<int>{});
    
    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(nums)/sizeof(int);
    sorter(nums,n);
    return 0;
}