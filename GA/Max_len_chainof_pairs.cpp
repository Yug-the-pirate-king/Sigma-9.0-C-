#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second <= p2.second;
}

int main()
{
    vector<pair<int , int>> pairs;
    pairs.push_back(make_pair(5,24));
    pairs.push_back(make_pair(39,60));
    pairs.push_back(make_pair(5,28));
    pairs.push_back(make_pair(27,40));
    pairs.push_back(make_pair(50,90));

    sort(pairs.begin(),pairs.end(),compare);

    int ans = 1;
    int currEnd = pairs[0].second;
    for(int i = 1;i<pairs.size();i++){
        if(pairs[i].first > currEnd){
            ans++;
            currEnd = pairs[i].second;
        }
    }

    cout << ans;
    return 0;
}