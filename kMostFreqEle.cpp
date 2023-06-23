#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    // base case 
    if (k==n){
        return arr;
    }
    unordered_map<int,int> m;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for (auto x: arr){
        m[x]++;
    }
    for (auto x : m){
        pq.push({x.second,x.first});
        if (pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
