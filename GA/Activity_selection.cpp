#include <iostream>
#include<vector>
using namespace std;

int Activity( vector<int> start, vector<int> end){
int currEnd = end[0];
int count = 1;

for(int i = 1;i<start.size();i++){
    if(start[i] >= currEnd){
        currEnd = end[i];
        count++; 
    }
}

return count ;
}

int main()
{
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout << "The max number of Activity : " << Activity(start,end);
    return 0;
}