#include <iostream>
using namespace std;

void counting_sort(int *nums, int n){
    int freq[100000];
    int minVal = INT16_MAX,maxVal = INT16_MIN;
    for(int i=0;i<n;i++){
        minVal = min(minVal,nums[i]);
        maxVal = max(maxVal,nums[i]);
    }

    for(int i= 0;i<n;i++){
        freq[nums[i]]++;
    }

    for(int i=minVal,j=0;i<=maxVal;i++){
        while(freq[i] > 0){
            nums[j++] = i;
            freq[i]--;
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(nums)/sizeof(int);
    counting_sort(nums,n);
    return 0;
}