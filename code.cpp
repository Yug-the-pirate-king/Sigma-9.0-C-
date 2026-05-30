#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

void myfunction(int n)
{
    string str = "";

    while (n > 0)
    {
        n--;
        int r = n%26;
        str.push_back('A'+r);
        n /= 26; 
    }

    reverse(str.begin(), str.end());

    cout << str;
}

int main()
{
    int n = 701;

    myfunction(n);

    return 0;
}