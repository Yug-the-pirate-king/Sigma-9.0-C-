#include <iostream>
using namespace std;

void trap(int *arr , int n){
    int leftMax[20000],rightMax[20000];
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];
    int waterTrap = 0;
    for(int i = 1;i <n;i++){
leftMax[i] = max(leftMax[i-1],arr[i]);
    }
     for(int i = n-2;i >=0;i--){
rightMax[i] = max(rightMax[i+1],arr[i]);
    }
for(int i=0;i<n;i++){
    int currwaterTrap = min(leftMax[i],rightMax[i]);
    if(currwaterTrap > 0){
        waterTrap += currwaterTrap - arr[i];
    }
}

cout << "The water Trapped is " << waterTrap;
}

int main() {
    int valley[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(valley)/sizeof(int);

    trap(valley,n);
    return 0;
}