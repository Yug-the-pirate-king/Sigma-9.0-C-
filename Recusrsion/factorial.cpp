#include <iostream>
using namespace std;
int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

    int
    main()
{
    int x= factorial(5);
    cout << x ;
    return 0;
}