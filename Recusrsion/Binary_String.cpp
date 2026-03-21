#include"../myheaders.h"

//Print all Binary Strings of size N without any consecutive 1s

void binary_String(int n , int lastplace, string ans){

    if(n == 0){
        cout << ans << "\n";
        return;
    }

    if(lastplace != 1){
        binary_String(n-1,0,ans+'0');
        binary_String(n-1,1,ans+'1');
    }
    else{
        binary_String(n-1,0,ans+'0');
    }

}

int main(){

    int n = 3;
    string ans = "";

    binary_String(n,0,ans);

    return 0;
}