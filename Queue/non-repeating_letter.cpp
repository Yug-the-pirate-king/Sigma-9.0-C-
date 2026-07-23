#include <iostream>
#include <queue>
#include<vector>
using namespace std;

 int firstUniqChar(string s) {
     vector<int> freq(26,0);
     queue<char> q1;
     for(int i = 0;i<s.size();i++){
        q1.push(s[i]);
        freq[s[i]-'a']++;
        while(!q1.empty() && freq[q1.front()-'a'] >1){
            q1.pop();
        }
     }

     if(q1.empty()){
        return -1;
     }
     int i = 0;
     while(s[i] != q1.front()){
        i++;
     }

     return i;
    }

int main() {
    string s = "aabccb";
     cout << firstUniqChar(s);
    
    return 0;
}