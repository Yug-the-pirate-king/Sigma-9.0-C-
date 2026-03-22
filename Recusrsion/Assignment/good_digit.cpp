#include "C:\Users\meena shah\Desktop\Sigma C++\myheaders.h"

long MOD = 1000000007;

long long countGoodNumber(long n)
{
    long even = (n+1)/2;
    long odd = (n)/2;

    return ((long long)pow(5,even)*(long long)pow(4,odd))%MOD;
}

int main()
{
    int n = 4;
    cout << countGoodNumber(n);
    return 0;
}