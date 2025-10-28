#include "../myheaders.h"

void Clearithbit(int n, int i) {
    cout << "Number after clearing bit " << i << " : " << (n & ~(1 << i)) << endl;
}


int main(){
    int n ,i;
    cout << "Enter the number :\n";
    cin >> n;
    cout << "Enter the postion :\n";
    cin >> i;

    Clearithbit(n,i);
}