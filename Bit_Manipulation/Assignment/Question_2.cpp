#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void non_empty(vector<int> num){
int ans = 0, Len = num.size();

for(int i =0;i<Len;i++){
    ans ^= num[i];
}

cout << ans;

}

int main(){
    vector<int> num = {4,2,2,1,1};

    non_empty(num);
}