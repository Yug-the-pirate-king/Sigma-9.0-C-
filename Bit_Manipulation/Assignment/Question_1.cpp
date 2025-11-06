#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void clear_Bit(int num,int i,int j){
     int allOnes = ~0;                // 111111... in binary
    int left = allOnes << (j + 1);   // 1110000... after j
    int right = (1 << i) - 1;        // 000...0111 up to i-1
    int mask = left | right;         // 111000...0111
    int result = num & mask;         // clears bits i–j

    cout << "Number after clearing bits from " << i << " to " << j << " = " << result << endl;
}

int main(){
    int num ,i,j;
    cout << "Enter the number : ";
    cin >> num;
    cout << "Enter the number form : ";
    cin >> i;
    cout << "to ";
    cin >> j;

    clear_Bit(num , i ,j);

}