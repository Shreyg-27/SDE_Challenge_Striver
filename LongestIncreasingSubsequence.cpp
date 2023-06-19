#include<bits/stdc++.h>
// int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
//     if(ind == n)
//         return 0;
        
//     if(dp[ind][prev_index+1]!=-1)
//         return dp[ind][prev_index+1];
    
//     int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
//     int take = 0;
    
//     if(prev_index == -1 || arr[ind] > arr[prev_index]){
//         take = 1 + getAns(arr,n,ind+1,ind,dp);
//     }
    
//     return dp[ind][prev_index+1] = max(notTake,take);

// }

// int longestIncreasingSubsequence(int arr[], int n)
// {
//     // Write Your Code here
//     vector<vector<int>> dp(n, vector<int>(n+1,-1));
//     return getAns(arr,n,0,-1,dp);
// }
int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int>temp;
  temp.push_back(arr[0]);
  int len=1;
  for(int i=1;i<n;i++)
  {
      if(arr[i]>temp.back())
      {
          temp.push_back(arr[i]);
          len++;
      }
      else
      {
          int idx=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
          temp[idx]=arr[i];
      }
  }
    return len;
}
