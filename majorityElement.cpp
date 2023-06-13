#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int count = n/2;
	int ans = -1;
	unordered_map<int,int> m;
	for (int i=0;i<n;i++){
		m[arr[i]]++;
	}
	for (int i=0;i<n;i++){
		if (m[arr[i]]>count){
			ans = arr[i];
		}
	}
	return ans;
}
