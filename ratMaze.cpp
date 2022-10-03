/* 
 Note: 
 To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right. 
 This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),  
 down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1). 
*/ 
#include<bits/stdc++.h> 
using namespace std; 
 
int maze[20][20]; 
 
void printSolution(int **solution,int n){ 
    for(int i=0;i<n;i++){ 
        for(int j = 0;j<n;j++){ 
            cout<<solution[i][j]<<" "; 
        } 
    } 
    cout<<endl; 
} 
 
void mazeHelp(int maze[][20],int n,int **solution,int row,int col){ 
     
    if(row == n-1 && col == n-1){ 
        solution[row][col] = 1; 
        printSolution(solution,n); 
        solution[row][col] = 0; 
        return; 
    } 
     
    if(row<0 || row >= n || col <0 || col >=n || maze[row][col] == 0 || solution[row][col] == 1){ 
        return; 
    } 
     
    solution[row][col]= 1; 
    mazeHelp(maze,n,solution,row-1,col); 
    mazeHelp(maze,n,solution,row+1,col); 
    mazeHelp(maze,n,solution,row,col-1); 
    mazeHelp(maze,n,solution,row,col+1); 
    solution[row][col] = 0; 
} 
 
void ratInMaze(int maze[][20],int n){ 
    int **solution = new int*[n]; 
    for(int i=0;i<n;i++){ 
        solution[i] = new int[n]; 
    } 
    for(int i=0;i<n;i++){ 
        memset(solution[i],0,n*sizeof(int)); 
    } 
    mazeHelp(maze,n,solution,0,0); 
} 
 
int main() { 
 int n; 
    cin>>n; 
     
    for(int i=0;i<n;i++){ 
        for(int j = 0;j<n;j++){ 
            cin>>maze[i][j]; 
        } 
    } 
    ratInMaze(maze,n); 
 // Write your code here 
 return 0; 
}
