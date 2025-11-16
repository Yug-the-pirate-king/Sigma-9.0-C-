#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void xorBeauty(vector<int> num){
int n = num.size();
int a = num[0];

for(int i=i;i<n;i++){
    a ^= num[i];
}

cout << a;

}

int main(){
    vector<int> num = {4,2,2,1,1};

    xorBeauty(num);
}