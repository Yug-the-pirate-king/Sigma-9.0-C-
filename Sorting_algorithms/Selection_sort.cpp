#include <iostream>
using namespace std;

void selection_sort( int *nums, int size)
{
    for(int i = 0;i<size;i++){
        int minIndex = i;
        for(int j=i+1;j<size;j++){
            if(nums[minIndex] > nums[j]){
                minIndex = j;
}
     }
     swap(nums[i],nums[minIndex]);
    }
    for(int i =0;i<size;i++){
    cout << nums[i] << " ";
}
}
int main() {
    int nums[] = {5,4,1,2,3};
    int size = sizeof(nums)/sizeof(int);

    selection_sort(nums,size);
    return 0;
}