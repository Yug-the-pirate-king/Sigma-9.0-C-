#include <iostream>
#include <list>
#include<iterator>
//Iterator in C++ are objects that allow you to traverse throught
//the elements of a container in a squential manner

using namespace std;

int main() {
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1); //1->2

    ll.push_back(3);
    ll.push_back(4); //1->2->3->4

    list<int>::iterator itr;

    for(itr = ll.begin();itr != ll.end();itr++){
        cout << (*itr) <<"->";
    }
    cout << "NULL";
    return 0;
}