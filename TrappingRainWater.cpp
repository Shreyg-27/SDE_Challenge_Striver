#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long res = 0;
    long left = 0;
    long right = n-1;
    long maxLeft = 0;
    long maxRight = 0;
    while (left<=right){
        if (arr[left]<=arr[right]){
            // check for left max, if less then update
            if (arr[left]>=maxLeft){
                maxLeft = arr[left];
            }
            else{
                // we need to add the result in the answer 
                res += maxLeft - arr[left];
            }
            left++;
        }
        else{
            // check for rightMx 
            if (arr[right]>=maxRight){
                maxRight = arr[right];
            }
            else{
                // add the value to res 
                res += maxRight - arr[right];
            }
            right--;
        }
    }
    return res;
}
