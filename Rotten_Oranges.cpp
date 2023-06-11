#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    // store the row, col with time 
    queue<pair<pair<int,int>, int>>q;
    int vis[n][m];
    int cntFresh = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            // if it is a rotten orange, 
            if (grid[i][j] == 2){
                q.push({{i,j},0});
                // make vis[i][j] = 2
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
            if (grid[i][j]==1){
                cntFresh+=1;
            }
        }
    }
    int time = 0;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    int cnt = 0;
    // bfs traversal till queue is empty 
    while (!q.empty()){
        int r = q.front().first.first;// row
        int c = q.front().first.second;// col
        int t = q.front().second; // time 
        time = max(time,t);
        q.pop(); 
        for (int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            // check for the valid cell and the unvisited fresh oranges 
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 
            && grid[nrow][ncol]==1){
                // push this in queue time + 1
                q.push({{nrow,ncol},t+1});
                // mark as rotten 
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    if (cnt != cntFresh){
        return -1;
    }
    return time;

}
