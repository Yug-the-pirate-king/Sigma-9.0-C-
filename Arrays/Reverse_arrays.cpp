#include <iostream>
using namespace std;

int main() {

    int nums[5] = {5, 4, 3, 9, 2};
    int rev[5] ;
    int n = 5;
    // int start = 0;
    // int end = n-1;

    // while(start < end){
    //   swap(nums[start],nums[end]);
    //   start++;
    //   end--;
    // }
    // for(int i = 0; i < n;i++){
    //    cout << nums[i];
    // }

    for(int i = 0 ; i < 5;i++){
        rev[i] = nums[n-i-1];
    }
     for(int i = 0; i < 5;i++){
       cout << rev[i];
    }
    return 0;
}