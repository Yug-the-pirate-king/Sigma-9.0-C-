#include <iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>> &sudoku,int row,int col,int n){
    for(int i = 0;i<9;i++){
        if(sudoku[row][i] == n || sudoku[i][col] == n){
            return false;
        }
    }
    int a = row/3;
    int b = col/3;

    a *= 3,b *= 3;

    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(sudoku[a+i][b+j] == n){
                return false;
            }
        }
    }

    return true;
}

void printSudoku(vector<vector<int>> &sudoku){
    for(int i=0;i<sudoku.size();i++){
        for(int j = 0;j<sudoku[0].size();j++){
            cout<< sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solver(vector<vector<int>> &sudoku,int row,int col){
     if(row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextrow = row;
    int nextcol = col+1;
    
    if(col == 8){
        nextrow = row+1;
        nextcol = 0;
    }

   

    if(sudoku[row][col] !=0){
        return solver(sudoku,nextrow,nextcol);
    }

    for(int i = 1;i<10;i++){
        if(isSafe(sudoku,row,col,i)){
            sudoku[row][col] = i;
            if(solver(sudoku,nextrow,nextcol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
    
}

int main()
{
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solver(sudoku,0,0);

    return 0;
}