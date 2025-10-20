#include "../myheaders.h"

int main(){
    char str1[100] = "Hello";
    char str2[100] = "World";

    char str3[100] = "abc";
    char str4[100] = "abc";
    strcat(str1, str2);
    
    //cout << str1;
    cout << strcmp(str3,str4) << "\n";
    cout <<strcmp(str1,str2);
}