#include "../myheaders.h"

int pair_sum__Brute_force(vector<int> arr,int key){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j] == key){
                cout << "{" << i << ","<< j<<"} \n";
                return 0;
            }
        }
    }
    return 1;
}
int pair_sum__correctway(vector<int> arr,int key){
    int start = 0,end = arr.size()-1;

    while(start<end){
       int sum = arr[start]+arr[end];
        if(sum == key){
          cout << "{" << start << ","<< end<<"} \n";
          return 0;
        }
        else if(sum < key){
            start++;
        }
        else {
            end--; 
        }
    }
    return 1;
}

int main(){

    vector<int> arr = {2,7,11,15};
    int key = 9;
    //pair_sum__Brute_force(arr,key);
    pair_sum__correctway(arr,key);

    return 0;
}