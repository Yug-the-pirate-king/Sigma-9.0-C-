#include <iostream>
using namespace std;

void bubble_sort(int *nums , int n){
   for(int i = 0;i < n-1;i++){
    for(int j = 0;j < n-i-1;j++){
    if(nums[j] > nums[j+1]){
        swap(nums[j],nums[j+1]);
    }}
   }
   for(int i =0;i<n;i++){
    cout << nums[i] << "\n";
}
}



int main() {
    int nums[] = {5,4,1,2,3};
    int size = sizeof(nums)/sizeof(int);

    bubble_sort(nums,size);
    return 0;
}