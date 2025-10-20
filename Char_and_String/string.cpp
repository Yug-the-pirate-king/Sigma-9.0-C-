#include "../myheaders.h"

int main(){
    string str ="hello";
    cout << str <<"\n";

    str = "World";
    cout << str <<"\n";

    getline(cin,str);

    cout<< str;
}