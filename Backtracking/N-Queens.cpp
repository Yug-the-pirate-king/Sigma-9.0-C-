#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void printboard(vector<vector<char>> board,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] <<" ";
        }
        cout << "\n";
        
    }
    
}

bool isSafe(vector<vector<char>> board,int row,int col){
    int n = board.size();
    for(int i = 0;i < n;i++){
        if(board[row][i] == 'Q' || board[i][col] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void NQueen(vector<vector<char>>& board, int row) {
    int n = board.size();
    if (row == n) {
        printboard(board, n);
        cout << "--------\n"; 
        return; 
    }

    for (int i = 0; i < n; i++) {

        
        if(isSafe(board,row,i)){
        board[row][i] = 'Q';
        NQueen(board, row + 1);
        board[row][i] = '.'; 
        }
    }
}

int main()
{
    vector<vector<char>> board;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;

        for (int j = 0; j < n; j++)
        {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    NQueen(board,0);

    return 0;
}