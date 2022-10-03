#include <bits/stdc++.h>

int helper(int* weight, int* value, int n, int maxWeight, int ** arr){
    if(maxWeight ==0 || n==0){
        return 0;
    }
	
    if(arr[n][maxWeight] !=-1){
        return arr[n][maxWeight];
    }
    
    if(maxWeight < weight[0]){
        return helper(weight+1, value+1, n-1, maxWeight,arr);
    }

    int a = value[0] + helper(weight+1, value+1, n-1, maxWeight-weight[0],arr);
    int b = helper(weight+1, value+1, n-1, maxWeight,arr);
    
    int ans = max(a,b);
    arr[n][maxWeight] = ans;
    
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **arr = new int*[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=new int[maxWeight+1];
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            arr[i][j]=-1;
        }
    }
    
    return helper(weight,value,n,maxWeight,arr);
}
