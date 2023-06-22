#include<bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);
    int plat_needed = 1;
    int result = 1;
    // second arrival and first departure comparison so 
    int i = 1;
    int j = 0;
    while (i<n && j<n){
        // case 1 
        if (at[i]<=dt[j]){
            // we would need another platform 
            plat_needed +=1;
            i++;
        }
        else if (at[i]>dt[j]){
            // we can use the same platform 
            plat_needed--;
            j++;
        }
        // now check for the max
        if (plat_needed > result){
            result = plat_needed;
        }
    }
    return result;
}
