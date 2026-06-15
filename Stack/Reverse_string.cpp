#include <iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string str){
    stack<char> s;
    string revstr = "";
    int n = str.size();
    for(int i = 0;i<n;i++){
        s.push(str[i]);
    }
    for(int i = 0;i<n;i++){
        revstr.push_back(s.top());
        s.pop();
    }

    return revstr;
}

int main()
{
    string str = "yug";

    cout << str << "\n";
    cout << reverse(str);
    return 0;
}