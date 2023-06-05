#include <bits/stdc++.h> 

void helper (int ind, vector<int> &arr, int n, vector<int> &ans, int sum){
    // base case 
    if (ind==n){
        ans.push_back(sum);
        return;
    }
    // if the ele is picked 
    helper(ind+1, arr, n, ans, sum+arr[ind]);
    // ele not picked 
    helper(ind+1, arr, n, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size();
    vector<int> ans;
    helper(0,num,n,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}
