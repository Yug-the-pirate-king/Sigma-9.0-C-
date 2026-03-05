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

int power

int main()
{

    cout << power(5, 2) <<"\n";

    return 0;
}