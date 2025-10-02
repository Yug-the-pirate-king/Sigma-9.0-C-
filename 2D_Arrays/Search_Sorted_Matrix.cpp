#include <iostream>
using namespace std;

void Burte_force(double nums[4][4],int key){

for(int i =0;i<4;i++){
    for(int j =0;j<4;j++){
        if(nums[i][j]== key){
            cout << "The Key is at X: " << i +1<<",Y: "<< j+1;
        }
    }
}
}

int main() {
    double nums[4][4] = {{10,20,30.40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int key = 32;
    Burte_force(nums,key); //n*n

    return 0;
}