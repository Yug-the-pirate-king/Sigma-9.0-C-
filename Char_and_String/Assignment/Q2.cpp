#include<iostream>
#include<string>
using namespace std;

void swapcheaker(string str1,string str2){
    bool ans = true;
    int count = 0;
    for(int i=0;i<str1.length();i++){
        if(str1[i] != str2[i]){
            count++;
        }
        if(count > 2){
            ans = false;
            break;
        }
    }

    cout << ans;
}

int main(){
    string str1 ="bank",str2 ="knab";

    swapcheaker(str1,str2);
}