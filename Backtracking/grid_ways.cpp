#include <iostream>
#include <vector>
using namespace std;

int ways(int r,int c,int fr,int fc){
    if(fr-1 == r && fc-1 == c){
        return 1;
    }

    if(r >= fr || c >= fc){
        return 0;
    }

    int vr = ways(r,c+1,fr,fc);
    int vd = ways(r+1,c,fr,fc);

    return vr+vd;
}

int main()
{
    int n = 3;
    int m = 2;

    cout << ways(0,0,n,m);

    return 0;
}