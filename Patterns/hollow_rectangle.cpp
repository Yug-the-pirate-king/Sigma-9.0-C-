#include <iostream>
using namespace std;

int main() {

    // 1.outer loop rows (1 to n times)

    // 1.inner loop each rows
//cout << "* "; // 1st
//for(n-2)
//cout << "* "; // 1st

    // 5*  but :- 1st + 3str + 1st
    // 2*  but :- 1st + 3space + 1st
    // 2*  but :- 1st + 3space + 1st
    // 5*  but :- 1st + 3str + 1st

    int n = 10;
    bool line ; 

    for(int i = 0;i < n;i++){
        line = (i == 0 || i == n-1)?true:false;

        cout << "* ";
        for(int j = 0;j < n-2 ; j++){
            if(line){
               cout << "* ";
            }else{
                cout << "  ";
            }
            
            
        }
        cout << "* ";
        cout << endl;
    }
    return 0;
}