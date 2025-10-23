#include <iostream>
#include <vector>
using namespace std;

void water(vector<int> heights){
    int max_water = 0,n = heights.size();
    int st = 0,end = n-1;
    while(st<end){
        max_water = max(max_water,min(heights[st],heights[end])*(end-st));

        if(heights[st]<heights[end]){
            st++;
        }else{
            end--;
        }
    }

    cout << max_water;
}

int main(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7}; 

    water(nums);
}