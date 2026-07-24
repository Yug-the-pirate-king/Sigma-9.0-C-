#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void Reverse(queue<int> &Q)
{
    stack<int> s;
    queue<int> q2 = Q;
    cout<< "Before Reveral : \n";
    while (!q2.empty())
    {
        cout << q2.front() << "|";
        q2.pop();
    }
    cout << "\n";
    while (!Q.empty())
    {
        s.push(Q.front());
        Q.pop();
    }
    while (!s.empty())
    {
        Q.push(s.top());
        s.pop();
    }
    q2 = Q;
    cout<< "After Reveral : \n";
    while (!q2.empty())
    {
        cout << q2.front() << "|";
        q2.pop();
    }
}

int main()
{
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);

    Reverse(Q);

    return 0;
}