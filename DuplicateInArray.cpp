#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	sort(arr.begin(),arr.end());
	for (int i =1;i<n;i++){
		if (arr[i-1]==arr[i]){
			return arr[i-1];
		}
	}
}
