#include <iostream>
#include<algorithm>
using namespace std;

void containsDuplicate(int *arr , int n){
sort(arr,arr+n);
bool a = false;
for(int i = 0;i <n-1;i++){
        if(arr[i]==arr[i+1]){
            a = true;
        }
       }
       if(a){
        cout << "True";
       }
       else{
        cout << "False";
       }

}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);

    containsDuplicate(arr , n);
    return 0;
}