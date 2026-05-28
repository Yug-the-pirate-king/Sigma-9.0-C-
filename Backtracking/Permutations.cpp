#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

void printPermutation(string str,string permutation){
    if(str.size() == 0){
        cout << permutation << "\n";
    }
    for(int i = 0;i < str.size();i++){
        char ch = str[i];
        printPermutation(str.substr(0,i)+str.substr(i+1,str.size()-i-1),permutation+ch);
    }
}

int main()
{
    string str = "abc";
    string permutation ="";

    printPermutation(str,permutation);
    
    return 0;
}