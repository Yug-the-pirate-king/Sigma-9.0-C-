#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int MinAbsoluteDiff(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res = 0;
    for(int i = 0;i<a.size();i++){
        res += abs(a[i]-b[i]);
    }

    return res;
}

int main()
{
    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};
    
    cout << MinAbsoluteDiff(a,b);
    return 0;
}