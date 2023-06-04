#include<bits/stdc++.h>
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	// int n = arr.size();
	// if (n==0){
	// 	return 0;
	// }
	// int xorr = 0;
	// for (int i=0;i<n;i++){
	// 	xorr = xorr^arr[i];
	// }
	// return xorr;
	int left =0;// left pointer 
	int right = arr.size()-1;// right pointer 
	while (left<right){
		int mid = left + (right-left)/2; // calculate the middle ele 
        // adjust the middle index to be even 
		if (mid%2==1){
			mid--;
		}
		// check if the middle ele is equal to the next ele 
		if (arr[mid]!=arr[mid+1]){
			right = mid;// the single ele is on the left side 
		}
		else{
			left = mid+2;// else the sib=ngle ele is on the right side 
		}
	}
	return arr[left];// return the single element 
}
