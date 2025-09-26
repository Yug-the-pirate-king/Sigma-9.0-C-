#include <iostream>
using namespace std;

void bubble_sort_desc(int *nums , int n){
   for(int i = 0;i < n-1;i++){
    for(int j = 0;j < n-i-1;j++){
    if(nums[j] <= nums[j+1]){
        swap(nums[j],nums[j+1]);
    }}
   }
//    for(int i =n-1;i>=0;i--){  //descending order the lazy way
//     cout << nums[i] << " ";
// }

for(int i =0;i<n;i++){
    cout << nums[i] << " ";
}
}

int main() {
    int nums[] = {3,6,2,1,8,7,4,5,3,1};
    int size = sizeof(nums)/sizeof(int);

    bubble_sort_desc(nums,size);
    return 0;
}