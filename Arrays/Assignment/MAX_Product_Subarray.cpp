#include <iostream>
using namespace std;

void MaxProsubArr(int *nums , int n){
    int ans = nums[0];
    int MaxPro = nums[0] ,MinPro = nums[0];

    for(int i = 1;i<n;i++){
        int curr = nums[i];

            // store before updating
            int tempMax = MaxPro;

             MaxPro = max(curr, max(curr * MaxPro, curr * MinPro));
             MinPro = min(curr, min(curr * tempMax, curr * MinPro));
            ans = max(ans, MaxPro);
    }

    cout << ans;
}

int main() {
    int nums[] = {2,3,-2,4};
    int n = sizeof(nums)/sizeof(int);
    
    MaxProsubArr(nums,n);
    return 0;
}