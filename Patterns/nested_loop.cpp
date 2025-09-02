#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1 ; i <= n ; i++){ // row 

        for(int j = 1 ; j <= n ; j++){ // column 

            cout << j << " ";

        }
        cout << endl;
    }
    return 0;
}