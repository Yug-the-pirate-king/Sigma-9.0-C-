#include <iostream>
using namespace std;

int power(int x, int n) // O(n)
{
    if (n == 0)
    {
        return 1;
    }

    return x * power(x, n - 1);
}

int powerfast(int x,int n){ //O(logn)
    if(n==0){
        return 1;
    }

    int halfpow = powerfast(x,n/2);
    int halfpowerSquare = halfpow * halfpow;

    if(n % 2 != 0){
        return x * halfpowerSquare;
    }
    return halfpowerSquare;
}

int main()
{

    cout << power(5, 2) <<"\n";
    cout << powerfast(5, 2) <<"\n";

    return 0;
}