#include "../myheaders.h"

int main(){

    // 1D Array
    int size;
    cout <<"Enter the size of arrays \n";
    cin >> size;

    int *arr = new int[size];

    for(int i=0;i<size;i++){
        arr[i]=1+i;
        cout << arr[i] <<" ";
    }

    // 2D Array
    int row ,col;
    cout << "Enter rows : ";
    cin >> row;
    cout << "Enter col : ";
    cin >> col;

    int* *martirx = new int*[row];

    for(int i=0;i<row;i++){
        martirx[i]=new int[col];
    }
    int a = 1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            martirx[i][j] = a++;
            cout << martirx[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}