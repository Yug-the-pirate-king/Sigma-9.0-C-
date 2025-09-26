   #include <iostream>
#include<algorithm>
using namespace std;

void sorter(char *nums, int n){

    // sort(nums,nums+n); // Ascending

    sort(nums,nums+n,greater<char>{});
    
    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    char nums[] = {'a','c','b','e','t','d','w','z'};
    int n = sizeof(nums)/sizeof(char);
    sorter(nums,n);
    return 0;
}