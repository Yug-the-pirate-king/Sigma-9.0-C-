#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int countInRange(vector<int> &nums,int num,int si,int ei){
    int count = 0;
    for(int i = si;i<=ei;i++){
         if(nums[i] == num){
            count++;
        }
    }
    return count;
}

int majorityelement(vector<int> &nums,int si,int ei){
    if(si == ei){
        return nums[si];
    }

    int mid = si +(ei-si)/2;

    int left = majorityelement(nums,si,mid);
    int right = majorityelement(nums,mid+1,ei);

    if(left == right){
        return left;
    }

    int leftCount = countInRange(nums,left,si,ei);
    int rightCount = countInRange(nums,right,si,ei);

    return leftCount > rightCount?left:right;

}


int main()
{
    vector<int> nums = {3,3,3,1,1,2,2,2,2,2};
    int n=nums.size();

    cout << majorityelement(nums,0,n-1);

}