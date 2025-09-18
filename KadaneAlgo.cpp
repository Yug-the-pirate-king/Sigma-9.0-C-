#include <iostream>
using namespace std;
void KadaneAlgorithm(int *arr , int n){
    int currsum = 0;
    int maxsum = INT32_MIN;
for(int i = 0;i < n;i++){
    currsum += arr[i];
    maxsum = max(currsum,maxsum);
    if(currsum <= 0){
        currsum = 0;
    }
}
cout << "The Large Sum of Subarray is " << maxsum;
}

int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    KadaneAlgorithm(arr , n);
    return 0;
}