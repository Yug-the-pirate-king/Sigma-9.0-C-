#include <iostream>
#include<queue>
using namespace std;
void interleave(queue<int> Q){
if(Q.size() % 2 != 0) {
    cout << "Odd len";
    return ;
}
int halfSize = Q.size() / 2;
queue<int> q1;
for(int i =0;i<halfSize;i++){
    q1.push(Q.front());
    Q.pop();
}
while(!q1.empty()){
    Q.push(q1.front());
    q1.pop();
    Q.push(Q.front());
    Q.pop();
}
queue<int> q2 = Q;
while (!q2.empty()){
    cout<< q2.front() << "|";
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

    interleave(Q);

    return 0;
}