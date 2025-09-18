#include <iostream>
using namespace std;

void MaxSubarraySum(int *arr , int n){
    int maxsum = INT32_MIN;
    for(int start = 0;start < n;start++){
    for (int end = start ; end < n;end++){
        int sum = 0;
        for (int i = start ; i <= end ;i++){
            sum += arr[i];
        }
        maxsum = (sum > maxsum)? sum : maxsum;
    }
}
cout << maxsum;
}
int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    MaxSubarraySum(arr , n);
    return 0;
}