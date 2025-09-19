#include <iostream>
using namespace std;

void maxProfit(int *prices ,int n){
    int maxprofit = INT32_MIN;
    for(int i = 0;i< n-1;i++){
        for(int j = 0;j<i;j++){
        maxprofit = max(maxprofit,(prices[j+1]-prices[j]));
        }
    }
    cout << maxprofit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int days = sizeof(prices)/sizeof(int);

    maxProfit(prices , days);
    return 0;
}