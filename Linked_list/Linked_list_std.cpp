#include <iostream>
#include <list>
#include<iterator>
//Iterator in C++ are objects that allow you to traverse throught
//the elements of a container in a squential manner

using namespace std;

void print_ll(list<int> ll){
    list<int>::iterator itr;

    for(itr = ll.begin();itr != ll.end();itr++){
        cout << (*itr) <<" -> ";
    }
    cout << "NULL\n";
}

int main() {
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1); //1->2

    ll.push_back(3);
    ll.push_back(4); //1->2->3->4

    print_ll(ll);

    cout << ll.size()<<"\n";

    cout << "Head " <<  ll.front() <<"\n";
    cout << "Tail "<< ll.back() << "\n";

    ll.pop_front();
    print_ll(ll);

    ll.pop_back();
    print_ll(ll);

    ll.insert(ll.begin(),3,99);
    print_ll(ll);
    return 0;
}