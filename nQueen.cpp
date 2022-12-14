#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int n,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0; i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 and j<n; i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    
    return true;
}

void nQueen(int n,int row){
    if(row == n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j] =1;
            nQueen(n,row+1);
            board[row][j]=0;
        }
    }
    return;
}

int main(){
    memset(board,0,11*11*sizeof(int));
    int n;
    cin >> n;
    nQueen(n,0);
    return 0;
}
