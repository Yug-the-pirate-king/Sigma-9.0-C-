#include <iostream>
using namespace std;

void Burte_force(double nums[4][4],int key){

for(int i =0;i<4;i++){
    for(int j =0;j<4;j++){
        if(nums[i][j]== key){
            cout << "The Key is at X: " << i +1<<",Y: "<< j+1;
            break;
        }
    }
}
}

void Row_lS_colum_BS(double nums[4][4],int key){
  for(int i =0;i<4;i++){
    int start = 0;
    int end = 3;
    while(start<=end){
        int mid = start + (end - start) / 2;
        if(nums[i][mid]==key){
          cout << "The Key is at X: " << i +1<<",Y: "<< mid+1;
            break;  
        }
        else if(nums[i][mid]>key){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
}
} 

void Staircase(double nums[4][4],int key){
int row=0;
int col = 3;

while (key != nums[row][col])
{
    if(nums[row][col] > key){
        col--;
    }else{
        row++;
    }
}
cout << "The Key is at X: " << row + 1<<",Y: "<< col+1;
}

int main() {
    double nums[4][4] = {{10,20,30.40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int key = 32;
    //Burte_force(nums,key); //n*n
    //Row_lS_colum_BS(nums,key); //n*logn
    Staircase(nums,key);

    return 0;
}