#include <iostream>
#include <stack>
using namespace std;

template<class T>
void Push_Buttom(stack<T> &stacks, T value)
{
    if (stacks.empty()){
        stacks.push(value);
        return;
    }
    T top = stacks.top();
    stacks.pop();
    Push_Buttom(stacks,value);
    stacks.push(top);
    return;
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    Push_Buttom(s,4);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }

    return 0;
}