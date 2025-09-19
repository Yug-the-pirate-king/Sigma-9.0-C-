#include <iostream>
using namespace std;

void maxProfit(int *prices ,int n){
    int maxprofit = 0, BestBuy = prices[0];
    for(int i = 1;i< n;i++){
        maxprofit = max(maxprofit,prices[i]-BestBuy);
        BestBuy = min(BestBuy,prices[i]);
    }

    cout << "The max profit is of " << maxprofit;

}

int main() {
    int prices[] = {1, 2, 3, 4, 5, 6, 7};
    int days = sizeof(prices)/sizeof(int);

    maxProfit(prices , days);
    return 0;
}