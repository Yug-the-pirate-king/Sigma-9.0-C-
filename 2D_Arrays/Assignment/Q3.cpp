#include<iostream>
using namespace std;

void Transpose(string arr[2][3]){
string Transpose_array[3][2];
for(int i =0 ;i<2;i++){
    for(int j=0;j<3;j++){
        Transpose_array[j][i] = arr[i][j];
    }
}

for(int i =0 ;i<3;i++){
    for(int j=0;j<2;j++){
        cout << Transpose_array[i][j] << " ";
    }
    cout << "\n";
}
}

int main(){
    string arr[2][3] = {{"a11","a12","a13"},{"a21","a22","a23"}};

    Transpose(arr);
}