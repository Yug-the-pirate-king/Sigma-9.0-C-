#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cout << "Enter two size of array: ";
    cin >> n >> m;
    int arr[n][m];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) { // row
        for (int j = 0; j < m; j++) { // column
            cin >> arr[i][j];
        }
    }
    cout << "Array elements are: " << endl;
    for (int i = 0; i < n; i++) { // row        
        for (int j = 0; j < m; j++) { // column
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   

    return 0;
}