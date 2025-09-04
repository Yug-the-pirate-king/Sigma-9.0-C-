#include <iostream>
using namespace std;

int sum(int a, int b){
    return a+b;
}

int diff(int a, int b){
    return a-b;
}
int main() {
    int a = 5 , b = 10;

   cout << "The Sum is " << sum(a,b) << endl; // 15

   cout << "The Diff is "<< diff(a,b); // -5
   
    return 0;
}