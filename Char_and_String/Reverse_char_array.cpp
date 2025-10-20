#include "../myheaders.h"

void reverse(char word[],int n){
    for(int i=0;i<=n/2;i++){
        swap(word[i],word[n-1-i]);
    }

    cout << word;
}

int main(){
    char word[] = "yug";
    int n = strlen(word);

    reverse(word,n);
}