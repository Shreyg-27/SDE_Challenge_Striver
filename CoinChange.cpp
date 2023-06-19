// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     //Write your code here
// }
#include<bits/stdc++.h>
long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>>t(n+1,vector<long>(value+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=0;j<value+1;j++){
            if(j==0&&i>0)
                t[i][j]=1;
            else if(a[i-1]<=j)
                t[i][j]=t[i][j-a[i-1]]+t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][value];
}
