#include <iostream>
#include<math.h>
using namespace std;

void sumOfDiagonal(int arr[][5]){
    int sum = 0;
    int n = 5;

    for(int i=0;i < n;i++){
        sum += arr[i][i] + arr[i][n-i-1];
    }

    if(n%2 != 0){
        sum -= arr[n / 2][n / 2];
    }

    cout << sum;
}

int main() {
     int arr[5][5] = {
    { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 }
};

sumOfDiagonal(arr);

    return 0;
}