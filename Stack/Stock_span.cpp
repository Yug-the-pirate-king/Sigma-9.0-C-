#include <iostream>
#include<vector>
#include <stack>
using namespace std;

class stock
{
    int val;
    int idx;
    public:
     stock(int val,int idx){
        this->val = val;
        this->idx = idx;
     }
};

void stockspanProblem(vector<int> &stock,vector<int> &span){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i =1;i<stock.size();i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        }else{
            int prevhigh = s.top();
            span[i] = i - prevhigh;
        }
    }
    cout << "[ ";
    for(int i = 0;i<span.size();i++){
        cout << span[i] <<", ";
    }
    cout << "]";
}

int
main()
{
    vector<int> stockdata = {100,80,60,70,60,85,100};
    vector<int> span = {0,0,0,0,0,0,0};

    stockspanProblem(stockdata,span);
    return 0;
}