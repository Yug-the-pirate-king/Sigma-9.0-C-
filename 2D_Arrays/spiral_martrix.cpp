#include <iostream>
using namespace std;

int main() {
    int n = 5,m=5;
    
    int arr[n][m] = {
    {  1,  2,  3,  4,  5 },
    {  6,  7,  8,  9, 10 },
    { 11, 12, 13, 14, 15 },
    { 16, 17, 18, 19, 20 },
    { 21, 22, 23, 24, 25 }
};

    for(int i = 0;i<3;i++){
    int TopRow = i;
    int LeftColum = i;
    int BottumRow = n-i-1;
    int RightColum = m-i-1;

    //top
    while(RightColum >= LeftColum){
        cout << arr[TopRow][LeftColum] << " ";
        LeftColum++;
    }
    LeftColum = i;
    TopRow++;

    //right
    while(BottumRow >= TopRow){
        cout << arr[TopRow][RightColum] << " ";
        TopRow++;
    }
    TopRow = i;
    RightColum--;

    //buttom
    while(RightColum >= i){
        cout << arr[BottumRow][RightColum] << " ";
        RightColum--;
    }
    RightColum = n+i-1;
BottumRow--;
    //left
    while(BottumRow > TopRow){
        cout << arr[BottumRow][LeftColum] << " ";
        BottumRow--;
    }
}
    return 0;

}