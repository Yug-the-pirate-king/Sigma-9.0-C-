#include <iostream>
using namespace std;

int main() {
    int num[5] = {5, 4, 3, 9, 2};
    int largest = num[0];
for(int i = 1;i < 5;i++){
    if(num[i] > largest){
        largest = num[i];
    }
}

cout << "The largest Number is equal to : " << largest;

    return 0;
}