#include <iostream>
using namespace std;

int factorial(int a){

 return a > 1?a * factorial(a-1):a;

} 
int binomial_coefficient(int n , int r){

    return (factorial(n)/(factorial(r)*factorial(n-r)));

}
int main() {
    int n = 4 , r = 2;

    cout << "The Binmial Coefficient : " << binomial_coefficient(n,r);

    
    return 0;
}