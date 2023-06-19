#include<bits/stdc++.h>
int maxCut(vector<int>&v,int n,int W,vector<vector<int>>&t){
    if(n==0||W==0)
        return t[n][W]=0;
    if(t[n][W]!=-1)
        return t[n][W];
    if(n<=W)
        return t[n][W]=max(v[n-1]+maxCut(v,n,W-n,t),maxCut(v,n-1,W,t));
    else if(n>W)
        return t[n][W]=maxCut(v,n-1,W,t);
}
    
    
int cutRod(vector<int> &v, int n)
{
    int W=n;
    vector<vector<int>> t(n+1,vector<int>(W+1,-1));
    return maxCut(v,n,W,t);
}
