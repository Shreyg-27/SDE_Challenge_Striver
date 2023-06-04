#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int ind = -1;
    // find the break point 
    for(int i=n-2;i>=0;i--){
        if (permutation[i]<permutation[i+1]){
            ind = i;
            break;
        }
    }
    // if break point does not exist - reverse the whole array 
    if (ind==-1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
     // Step 2: Find the next greater element
    //         and swap it with arr[ind]:
    for (int i=n-1;i>ind;i--){
        if (permutation[i]>permutation[ind]){
            swap(permutation[i],permutation[ind]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(permutation.begin()+ind+1, permutation.end());
    return permutation;

}
