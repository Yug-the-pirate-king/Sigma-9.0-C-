#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int maxarea(vector<int> &height){
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    stack<int> t;

    nsl[0] = -1;
    s.push(0);

    for(int i=1;i<height.size();i++){
        int curr= height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i] = -1;
        }
        else{
            nsl[i] = s.top();
        }
        s.push(i);
    }


    for(int i=n-1;i >= 0;i--){
        int curr= height[i];
        while(!t.empty() && curr <= height[t.top()]){
            t.pop();
        }

        if(t.empty()){
            nsr[i] = n;
        }
        else{
            nsr[i] = t.top();
        }
        t.push(i);
    }
    int maxarea = 0;
    int area = 0;
    for(int i=0;i<n;i++){
        area = height[i] * (nsr[i]-nsl[i]-1);

        maxarea = max(area,maxarea);
    }

    return maxarea;

}

int main()
{
    vector<int> height = {2,1,5,6,2,3};

    cout << maxarea(height);


    return 0;
}