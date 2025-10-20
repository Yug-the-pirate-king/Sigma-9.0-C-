#include<iostream>
#include<string>
using namespace std;

void count_Vowels(string word){
    char count[26]={0};
    for(char ch:word){
        count[ch-'a']++;
    }

    int ans = count[0]+count['e'-'a']+count['i'-'a']+count['o'-'a']+count['u'-'a'];

    cout << "The Total number of vowel : "<< ans;
}

int main(){
    string word;
    cout << "Enter a word : \n";
    getline(cin,word);

    count_Vowels(word); //a, e, i, o, u

}