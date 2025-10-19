#include<myheaders.h>

int main(){
    char ch1 = 'a';
    char ch2 = 'X';
    char ch3 = '%';
    char ch4 = '9';
    char ch5 = '\n'; // next line char -> \n
    //ASCII A -> 65 and a -> 97

    // we can find postion between two char by
    char ch = 'f';

    int postion = ch - ch1; // 5
    
    // Char Arr

    char arr[] = {'a','b','c','d','e','\0'}; // arr[6] \0 also take space in array

    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;
    // cout << arr[3] << endl;
    // cout << arr[4] << endl;
    // cout << arr;

    char word[50];
    cout
    cin >> word; //after space nothing is included

    cout << "You word is :" << word << "\n";
    cout << "The length is :"<< strlen(word);

    char sentence[50];
    cin.getline(sentence,50);

    cout << "You word is :" << sentence << "\n";
    cout << "The length is :"<< strlen(sentence);


    return 0;
}