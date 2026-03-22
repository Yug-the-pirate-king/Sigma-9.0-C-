#include "C:\Users\meena shah\Desktop\Sigma C++\myheaders.h"

void occurrences(vector<int> &myarr,int key,int i){
if(myarr[i] == key){
cout << i <<" ";
}
if(i == myarr.size()-1){
return;
}
occurrences(myarr,key,++i);
}

int main(){
    vector<int> myarr = {3,2,4,5,6,2,7,2,2};
    int key = 2;

    occurrences(myarr,key,0);
    return 0;
}