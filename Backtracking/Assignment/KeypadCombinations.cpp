#include <iostream>
#include<vector>
#include <string>
using namespace std;

void bfs(int pos,int len,string ans,string dig,vector<vector<char>> L){
    if(pos == len){
        cout << ans << "\n";
    }
    else{
        vector<char> letters = L[dig[pos]-'0'];
    
    for(int i = 0;i < letters.size();i++){
        bfs(pos+1,len,ans+letters[i],dig,L);
    }}
}

void ways(string dig, vector<vector<char>> L){
int len = dig.size();
if(len == 0){
    cout << "";
    return;
}

string ans = "";
bfs(0,len,ans,dig,L);

}


int main()
{
    vector<vector<char>> L = {{}, {}, {'a', 'b','c'},
                              {'d','e','f',},
                              {'g', 'h', 'i'},
                              {'j', 'k', 'l'},
                              {'m', 'n', 'o'},
                              {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'},
                              {'w', 'x', 'y', 'z'}};

    string dig = "23";

    ways(dig, L);
    return 0;
}