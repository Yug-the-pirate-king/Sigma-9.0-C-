#include "../myheaders.h"
using namespace std;

int tp(int n){ // 2*n

if(n == 0 || n == 1){
    return 1;
}
    // vertical
    int ans1 = tp(n - 1);

    // horizontal
    int ans2 = tp(n - 2);

    return ans1 + ans2;
}

int main()
{
    int n = 5;
    cout << tp(n);
    return 0;
}