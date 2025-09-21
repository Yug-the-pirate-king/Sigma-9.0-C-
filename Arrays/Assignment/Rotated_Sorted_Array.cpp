#include <iostream>
using namespace std;

void Search(int *array,int n,int size){
    int st = 0, end = size-1;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(array[mid] == n){
            cout << mid;
        }

        if(array[st] <= array[mid]){
            if(array[st] <= n && n <= array[mid]){
                end = mid -1;
            }else{
                st = mid+1;
            }
        }else{
             if(array[end] >= n && n >= array[mid]){
                st = mid + 1;
            }else{
                end = mid-1;
            }
        }
    }
}

int main() {
    int rotated_array[] = {0,1,2,3,4,5,6,7};
    int size = sizeof(rotated_array)/sizeof(int);
    int target = 5;

    Search(rotated_array,target,size);
    return 0;
}