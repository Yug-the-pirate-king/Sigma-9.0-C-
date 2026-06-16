#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool Duplicate_parentheses(string str)
{
    stack<char> s;
    s.push(str[0]);
    for (int i = 1; i < str.size(); i++)
    {
        if (s.top() == '(' && str[i] == ')')
        {
            return false;
        }
        if (str[i] == ')')
        {
            while (s.top() != '(')
            {
                s.pop();
            }
            s.pop();
            continue;
        }
        s.push(str[i]);
    }

    return true;
}

int main()
{
    string str = "((a+b))";

    cout << Duplicate_parentheses(str);
    return 0;
}