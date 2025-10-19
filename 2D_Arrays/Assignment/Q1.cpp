#include<iostream>
using namespace std;

void find(int arr[2][3] , int n ,int m,int key){
    int output = 0;
    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]==key){
                output++;
            }
        }
    }

    cout << "Output -" << output;
}

int main(){
    int arr[2][3] = {{4,7,8},{8,8,7}};
    int key = 7;
    find(arr ,2,3,key);

}