#include "../myheaders.h"

int partition(vector<int> &arr ,int si,int ei){
    int i = si-1;
    for(int j = si;j<ei;j++){
        if(arr[j] < arr[ei]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);

    return i;
}

void quick_sort(vector<int> &arr ,int si,int ei){

    if(si >= ei){
        return;
    }

    int pivotIdx = partition(arr,si,ei);

    quick_sort(arr,si,pivotIdx-1);
    quick_sort(arr,pivotIdx+1,ei);


}

void printArr(vector<int> arr)
{
    int n = arr.size();
    cout << "The arr is :\n";
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {6, 3, 7, 5, 2, 4};
    int n = arr.size();

    quick_sort(arr,0,n-1);

    printArr(arr);
    return 0;
}