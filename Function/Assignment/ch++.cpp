#include <iostream>
using namespace std;

char next_term (char ch){
    if(ch == 'z'){
        return 'a';
    }else{
        return ++ch;
    }
}

int main() {
    char ch = 'z';

    cout << "The next term is " << next_term(ch);
    return 0;
}