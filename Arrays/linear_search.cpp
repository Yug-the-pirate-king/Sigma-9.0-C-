#include <iostream>
using namespace std;
void linear_search(int arr[], int n, int key){
    
    for(int i = 0 ;i < n;i++){
        if(arr[i] == key){
            cout << i;
            break;
        }
    }
}

int main() {
    int nums[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(nums)/sizeof(int);
    int key = 10;
    linear_search(nums,n,key);
return 0;
}