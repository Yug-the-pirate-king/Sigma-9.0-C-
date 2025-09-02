#include <iostream>
using namespace std;

int main() {

    //  1. outer loop rows (1 to n times)

    // 2. inner loop each rows (1 to p times)

    // 3. work ?
    //cout << char;
    // char++

    int n = 10;
    int a = 1 ;

    for(int i = 0;i < n;i++){

        for(int j = 0 ; j < i;j++){

            cout << a++;
            
        }
        cout << endl;
    }
    return 0;
}