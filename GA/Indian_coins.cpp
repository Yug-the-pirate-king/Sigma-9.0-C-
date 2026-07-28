#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int V = 590;
    int n = coins.size();
    int ans =0;
   for(int i = n-1; i>= 0 && V >0;i--){
    if(V >= coins[i]){
        ans += V/coins[i];
        V %= coins[i];
    }
   }

   cout << ans;
    return 0;
}