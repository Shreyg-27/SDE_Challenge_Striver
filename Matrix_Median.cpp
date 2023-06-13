#include<bits/stdc++.h>

int countSmallerThanMid(vector<int> &row, int mid){
    int l = 0;
    int h = row.size()-1;
    while (l<=h){
        int md = (l+h) >> 1;
        if (row[md] <= mid){
            l = md+1;
        }
        else{
            h = md-1;
        }
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 0;
    int high = 1e5;
    int n = matrix.size();
    int m = matrix[0].size();
    while (low<=high){
        int mid = (low+high)>>1;
        int count = 0;
        for (int i=0;i<n;i++){
            // row wise calc numbers smaller than equla to mid
            count += countSmallerThanMid(matrix[i],mid);
        }
        if (count<= (n*m)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
