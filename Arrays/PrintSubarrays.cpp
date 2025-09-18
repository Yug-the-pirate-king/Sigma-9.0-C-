#include <iostream>
using namespace std;

void printSubArray(int *arr,int n){
for(int start = 0;start < n;start++){
    for (int end = start ; end < n;end++){
        for (int i = start ; i <= end ;i++){
            cout << arr[i];
        }
        cout << ",";
    }
    cout << "\n";
}
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printSubArray(arr,5);
    return 0;
}