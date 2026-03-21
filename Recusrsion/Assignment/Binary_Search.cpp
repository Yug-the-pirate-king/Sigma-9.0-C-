#include <iostream>
using namespace std;

int Binary_Search(int arr[],int left, int right ,int key)
{
int mid = left +(right-left)/2;
if(arr[mid] == key){
    return mid;
}

if(arr[mid] > key){
    return Binary_Search(arr,left,mid-1,key);
}

return Binary_Search(arr,mid+1,right,key);

}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    int key = 5;

    cout << Binary_Search(arr,0,7,5);

    return 0;
}