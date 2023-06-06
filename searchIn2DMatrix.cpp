#include<bits/stdc++.h>
bool searchMatrix(vector<vector<int>>& mat, int target) {
    // length of the id array 
    int psuedolength = (mat.size() * mat[0].size());
    int col_length = mat[0].size();
    int low = 0;
    int high = psuedolength-1;
    while (low<=high){
        int mid = (low+high)/2;
        int actualRowIndex = mid/col_length;
        int actualColIndex = mid%col_length;

        if (mat[actualRowIndex][actualColIndex]==target){
            return true;
        }
        else if (mat[actualRowIndex][actualColIndex]>target){
            high = mid-1;

        }
                
            
        else{
            low=mid+1;
        }
                
    }
    return false;
        
}
