#include "../myheaders.h"

int Search_in_Rotated_sorted_array(vector<int> &arr,int si,int ei,int target){
    int mid = si + (ei-si)/2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[si] <= arr[mid]){
        if(arr[si] <= target && target <= arr[mid]){
            return Search_in_Rotated_sorted_array(arr,si,mid-1,target);
        }
        else{
           return  Search_in_Rotated_sorted_array(arr,mid+1,ei,target);
        }
    }else{
        if(arr[mid] <= target && target <= arr[ei]){
           return  Search_in_Rotated_sorted_array(arr,mid+1,ei,target);
        }
        else{
          return   Search_in_Rotated_sorted_array(arr,si,mid-1,target);
        }
    }
}

int main(){
    vector<int> arr ={4,5,6,7,0,1,2};
    int n = arr.size();

    cout << Search_in_Rotated_sorted_array(arr,0,n-1,0);
}