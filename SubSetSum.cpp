#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int dp[n+1][k+1];
    for (int i=0;i<n+1;i++){
        for (int j=0;j<k+1;j++){
            if (i==0){
                dp[i][j] =0;
            }
            if (j==0){
                dp[i][j] = 0;
            }
        }
    }
    for (int i=1;i<n+1;i++){
        for (int j =1;j<k+1;j++){
            if (arr[i-1]<=j){
                // here we have 2 things to take it or not, and 
                /// if either of it gives true, it will be true
                dp[i][j] = (dp[i][j-arr[i-1]]) || (dp[i-1][j]);
            }
            else{
                // the ele is greater than sum so we will not reduce j
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}
