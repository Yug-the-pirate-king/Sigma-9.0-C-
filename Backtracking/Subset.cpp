#include <iostream>
#include <cstring>
using namespace std;

void printSubset(string set,string subset){

    if(set.size() == 0){
        cout << subset << "\n";
        return;
    }
    char ch = set[0];

    printSubset(set.substr(1,set.size()-1),subset + ch);

    printSubset(set.substr(1,set.size()-1),subset);
}

int main()
{

    string set = "abc";

    string subset = "";

    printSubset(set,subset);

    return 0;
}