#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second >= p2.second;
}
int main()
{
    vector<pair<int, int>> jobs;
    jobs.push_back(make_pair(4, 20));
    jobs.push_back(make_pair(1, 10));
    jobs.push_back(make_pair(1, 40));
    jobs.push_back(make_pair(1, 30));

    sort(jobs.begin(), jobs.end(), compare);
    int porfit = jobs[0].second;
    int currjobend = 1;
    for(int i= 0;i<jobs.size();i++){
        if(jobs[i].first>currjobend){
            porfit += jobs[i].second;
            currjobend++;
        }
    }

    cout << porfit;
    return 0;
}