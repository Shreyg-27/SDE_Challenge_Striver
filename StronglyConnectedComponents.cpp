#include<bits/stdc++.h>

void topologicalSort(vector<int> adj[], int s, bool vis[], stack<int> &st){
    vis[s] = true;
    for (int v : adj[s]){
        if (!vis[v]){
            topologicalSort(adj,v,vis,st);
        }
    }
    st.push(s);
}

void dfs(vector<int> adj[], int s, bool vis[], vector<int> &ans){
    vis[s] = true;
    ans.push_back(s);
    for (int v : adj[s]){
        if (!vis[v]){
            dfs(adj,v,vis,ans);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj1[n];
    vector<int> adj2[n];

    bool vis[n] = {0};
    stack<int> st;
    vector<vector<int>>res;
    for (auto i : edges){
        adj1[i[0]].push_back(i[1]);
    }
    for (int i =0;i<n;i++){
        if (!vis[i]){
            topologicalSort(adj1,i,vis,st);
        }
    }

    for (auto i : edges){
        adj2[i[1]].push_back(i[0]);
    }

    fill(vis,vis+n,0);

    while (!st.empty()){
        int u = st.top();
        st.pop();
        vector<int> ans;
        if (!vis[u]){
            dfs(adj2,u,vis,ans);
            res.push_back(ans);
        }
    }
    return res;

}
