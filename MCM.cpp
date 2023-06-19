#include <bits/stdc++.h> 

int solve(vector<int> &arr, int N, int i, int j, vector<vector<int>> &dp){
    if (i>=j){
        return 0;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    else{
        int res = INT_MAX;
        for (int k=i;k<j;k++){
            int temp = solve(arr,N,i,k,dp) + solve(arr,N,k+1,j,dp) + 
            (arr[i-1]*arr[k]*arr[j]);
            res = min(res,temp);
        }
        return dp[i][j] = res;
    }
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(101,vector<int>(101,-1));
    int i = 1;
    int j = N-1;
    return solve(arr,N,i,j,dp);
}
