void dfs(int row, int col,vector<vector<int>>&ans, vector<vector<int>> &image, 
int newColor, int delrow[], int delcol[],int iniColor){
    // colour with the new colour 
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    // check for the neighbours 
    for (int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid coordinate, 
        // chack for the same initial colour 
        // check for the unvisited pixel 
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor
        && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol,ans, image, newColor, delrow, delcol, iniColor);
        }
    }

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int iniColor = image[x][y];
    vector<vector<int>> ans = image;
    // copy the whole matrix in ans vector 
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    dfs(x, y, ans,image, newColor, delrow, delcol,iniColor);
    return ans;

}
