#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> value = {60,100,120};
    vector<int> weight = {10,20,30};
    vector<int> V_W;
    int W = 50;
    for(int i = 0;i<value.size();i++){
        V_W.push_back(value[i]/weight[i]);
    }
    int curr = 0; 
    int i = 0;
    int totalval = 0;
    while(curr != W){
        if((W-curr-weight[i] > -1)){
            curr += weight[i];
            totalval += value[i];
            i++;
        }else{
            totalval += (W-curr)*V_W[i];
            curr += (W-curr);
        }
    }

    cout << totalval;

    return 0;
}