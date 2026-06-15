#include <iostream>
#include <stack>
using namespace std;

void Push_Buttom(stack<char> &s, char value)
{
    if (s.empty())
    {
        s.push(value);
        return;
    }
    char top = s.top();
    s.pop();
    Push_Buttom(s, value);
    s.push(top);
}

void reverse_stack(stack<char> &s)
{
    if (s.empty()) 
    {
        return;
    }
    char temp = s.top();
    s.pop();
    reverse_stack(s);
    Push_Buttom(s, temp);
}

int main()
{
    stack<char> s;
    s.push('E');
    s.push('D');
    s.push('C');
    s.push('B');
    s.push('A');

    reverse_stack(s);

    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }

    return 0;
}