#include <bits/stdc++.h>

bool isValid(int x, int y, int n, vector<vector<int>> &vis, vector<vector<int>> &maze){
  if ((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]==0 && maze[x][y]==1){
    return true;
  }
  else{
    return false;
  }
}

void findPath(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &vis,
vector<vector<int>> &ans){
  // base case 
  if (x==n-1 && y==n-1){
    vector<int> temp;
    vis[x][y] = 1;
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        temp.push_back(vis[i][j]);
      }
    }
    // for the case of recursion other case backtrack
    vis[x][y] = 0;
    ans.push_back(temp); 
  }

  vis[x][y] = 1;

  // down 
  int newX = x+1;
  int newY = y;
  if (isValid(newX,newY,n,vis,maze)){
    findPath(newX, newY, maze, n, vis,ans);
  }

  // up 
  newX = x-1;
  newY = y;
  if (isValid(newX,newY,n,vis,maze)){
    findPath(newX, newY, maze, n, vis,ans);
  }

  // left 
  newX = x;
  newY = y-1;

  if (isValid(newX,newY,n,vis,maze)){
    findPath(newX, newY, maze, n, vis,ans);
  }

  // right 

  newX = x;
  newY = y+1;
  if (isValid(newX,newY,n,vis,maze)){
    findPath(newX, newY, maze, n, vis,ans);
  }

  vis[x][y] = 0;

}


vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> vis(n, vector<int> (n, 0));
  vector<vector<int>> ans;
  if (maze[0][0]==0){
    return ans;
  }
  findPath(0,0,maze,n,vis,ans);
  return ans;

}
