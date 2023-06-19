#include<bits/stdc++.h>

int helper(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
    if (i<0){
        return j+1;
    }
    if (j<0){
        return i+1;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    if (str1[i]==str2[j]){
        dp[i][j] = 0 + helper(str1,str2,i-1,j-1,dp);
    }
    else{
        dp[i][j] = 1+min(helper(str1,str2,i-1,j-1,dp),
    min(helper(str1,str2,i-1,j,dp),helper(str1,str2,i,j-1,dp)));
    }
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(str1,str2, n-1,m-1,dp);
}
