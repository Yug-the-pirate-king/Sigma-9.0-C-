#include <iostream>
using namespace std;

void Search(int *array,int n,int size){

}

int main() {
    int rotated_array[] = {3,4,5,6,7,0,1,2};
    int size = sizeof(rotated_array)/sizeof(int);
    int target = 5;

    Search(rotated_array,target,size);
    return 0;
}