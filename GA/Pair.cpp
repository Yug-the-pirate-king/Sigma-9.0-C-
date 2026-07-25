#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Pair in C++
//  STL container to store 2 objects

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second <= p2.second;
}

int main()
{
    vector<int> start = {0, 1, 3};
    vector<int> end = {9, 2, 4};

    vector<pair<int, int>> act(3, make_pair(0, 0));
    act[0] = make_pair(0, 9);
    act[1] = make_pair(1, 2);
    act[2] = make_pair(3, 4);

    for (int i = 0; i < act.size(); i++)
    {
        cout << "(" << act[i].first << "," << act[i].second << ")\n";
    }

    sort(act.begin(),act.end(),compare);
    cout << "------- Sorted ------- \n";
    for (int i = 0; i < act.size(); i++)
    {
        cout << "(" << act[i].first << "," << act[i].second << ")\n";
    }
    return 0;
}