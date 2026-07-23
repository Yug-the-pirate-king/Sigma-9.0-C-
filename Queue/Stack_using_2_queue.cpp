#include <iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
        void push(int data){
        q2.push(data);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        }

        void pop(){
            if(q1.empty()){
                cout << "underflow";
                return;
            }
            q1.pop();
        }

        int front(){
            if(q1.empty()){
                return -1;
            }
            return q1.front();
        }
        void print_Queue(){
            queue<int> temp = q1;
            while(!temp.empty()){
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << "\n";
        }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print_Queue();
    cout << s.front() << endl;
    s.pop();
    cout << s.front() << endl;
    s.pop();
    cout << s.front() << endl;
    s.pop();
    s.print_Queue();
    return 0;
}