#include <iostream>
using namespace std;
void mat_point1(int arr[][5],int n,int m){
cout << "0th row ptr "<< arr << endl;
cout << "1st row ptr "<< arr+1 << endl; // pointer of the row not cell
cout << "2nd row ptr "<< arr +2<< endl;
cout << "3th row ptr "<< arr +3<< endl;
cout << "4th row ptr "<< arr +4<< endl; 

//note 
//arr -> hex
//*arr -> hex but value of the row
//*(*arr) -> is int value of the 0th row and 0th col

//val using loop and ptr
for(int i=0;i<n;i++){
for(int j =0;j<m;j++){
cout << *(*(arr+i)+j) << " ";
}
}
}

int main() {
    int arr[5][5] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10 }, 
    { 11, 12, 13, 14, 15 }, 
    { 16, 17, 18, 19, 20 },
    { 21, 22, 23, 24, 25 }};

    mat_point1(arr,5,5);



    return 0;
}