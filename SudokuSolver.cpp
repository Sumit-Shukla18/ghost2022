//Q:  A 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.



#include<bits/stdc++.h>
using namespace std;
int board[9][9];

pair<int,int> findEmptyPosition(int board[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == 0){
                pair<int,int> p;
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    pair<int,int> p;
                p.first = -1;
                p.second = -1;
                return p;
}

bool canplace(int board[9][9], int numtoplace,pair<int,int> position){
    //check for row
    for(int i=0;i<9;i++){
        if(board[position.first][i] == numtoplace){
            return false;
        }
    }
    //check for column
    for(int i=0;i<9;i++){
        if(board[i][position.second] == numtoplace){
            return false;
        }
    }
    
    //check for 3x3
    int rowfactor = position.first - (position.first%3);
    int colfactor = position.second - (position.second%3);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+rowfactor][j+colfactor] == numtoplace){
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(int board[9][9]){
    pair<int,int> position = findEmptyPosition(board);
    if(position.first == -1 && position.second == -1){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(canplace(board,i,position)){
            board[position.first][position.second] = i;
        	bool ans = solveSudoku(board);
            if(ans){
                return true;
            }
             board[position.first][position.second] = 0;
             
        }
    }
    return false;
    
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    bool ans = solveSudoku(board);
    ans == true?cout<<"true":cout<<"false";
    // write your code here
    return 0;
}
