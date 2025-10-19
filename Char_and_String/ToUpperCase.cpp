#include "../myheaders.h"

void to_upper_Case(char word[],int n){
for(int i=0;i<n;i++){
    char ch = word[i];
    if('A'>= ch && ch <='Z'){
    }else if(ch >= 'a' && ch <= 'z'){
        word[i] = ch+'A'-'a';
    }
}

cout << "The word is :" << word;
}

int main(){
    char word[] = "ApPle";
    int n =strlen(word);

    to_upper_Case(word, n);
}



