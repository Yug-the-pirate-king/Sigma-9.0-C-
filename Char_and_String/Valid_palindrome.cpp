#include "../myheaders.h"

void valid_palindrome(char word[],int n){
bool ispalindrome = true;
int start = 0,end = n-1;
while(start<end){
    if(word[start++]!=word[end--]){
        ispalindrome = false;
        break;
    }
}

cout << "is the word palindrome : " << ispalindrome;

}

int main(){
    char word[] = "yuy"; // true
    int n = strlen(word);

    valid_palindrome(word,n);
}