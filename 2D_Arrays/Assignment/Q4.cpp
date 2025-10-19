#include <iostream>
using namespace std;

void one_to_two(int nums[],int n,int m,int size){
    int a = size;
    int output[n][m];
    if(n*m == a){
   int x = 0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        output[i][j] = nums[x++];
    }}
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout << output[i][j] << " ";
    }
    cout << "\n";
   }}
    else{
 output[0][0] = {};
    cout << *(*(output));
    }

}

int main() {
    int nums[] ={1,2,3,4,5};
    int n = sizeof(nums)/sizeof(int);
    one_to_two(nums,2,2,n);
    return 0;
}