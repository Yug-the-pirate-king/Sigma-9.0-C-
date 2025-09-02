#include <iostream>
using namespace std;

int main() {

    // outer loop rows (1 to n times)
    // inner loop each rows(column)

    int n = 5;

    for(int i = 0;i < n;i++){
        
        for(int j = 0;j <= i ; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}