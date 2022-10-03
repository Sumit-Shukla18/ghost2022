//Q: It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
// But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, 
// and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's 
// in the biggest piece of '1's for Gary ?



#include<bits/stdc++.h>

int countsize(vector<vector<int>> &cake, int n,vector<vector<bool>> &visited,int i,int j ){
    visited[i][j] = true;
    //up
    int ans = 0;
    if(i-1 >= 0 && cake[i-1][j] == 1 && visited[i-1][j] == false){
        ans += countsize(cake,n,visited,i-1,j);
    }
    //down
    if(i+1 < n && cake[i+1][j] == 1 && visited[i+1][j] == false){
        ans += countsize(cake,n,visited,i+1,j);
    }
    //left
    if(j-1 >= 0 && cake[i][j-1] == 1 && visited[i][j-1] == false){
        ans += countsize(cake,n,visited,i,j-1);
    }
    //right
    if(j+1 < n && cake[i][j+1] == 1 && visited[i][j+1] == false){
        ans += countsize(cake,n,visited,i,j+1);
    }
    return ans+1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
     vector<vector<bool>> visited(n,vector<bool>(n,false));
    int maxcount = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                int count = countsize(cake,n,visited,i,j);
            	maxcount = max(maxcount,count);
            }
        }
    }

    return maxcount;
}
