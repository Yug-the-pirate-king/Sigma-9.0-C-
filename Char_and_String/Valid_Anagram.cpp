#include "../myheaders.h"

bool Valid_Anagram(string str1,string str2,int n,int m){
if(n != m){
    cout << "They are not Anagram";
    return false;
}
int count[26]={};
for(char ch:str1){
    count[ch-'a']++;
}
for(char ch:str2){
    count[ch-'a']--;
    if(count[ch-'a'] == -1){
      cout << "They are not Anagram";
      return false;
    }
}
cout << "They are Anagram";
      return true;
}

int main(){
    string str1 = "yug",str2 = "gay";
    int n =str1.length(),m = str2.length();

    Valid_Anagram(str1,str2,n,m);
}