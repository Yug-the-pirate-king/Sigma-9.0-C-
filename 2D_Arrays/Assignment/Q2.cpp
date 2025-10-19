#include<iostream>
using namespace std;

void sum_of_row(int nums[3][3]){
    int sum = 0;
    for(int i=0;i<3;i++){
        sum += nums[1][i];
    }

    cout << "Output - " << sum;
}


int main(){
    int nums[3][3] = {{1,4,9},{11,4,3},{2,2,3}};

    sum_of_row(nums);
}