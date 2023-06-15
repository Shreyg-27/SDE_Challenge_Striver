// #include <bits/stdc++.h>

// vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
// 	// Write your code here.
// 	int left = m-1;
// 	int right = 0;
	
//     //Swap the elements until arr1[left] is
//     // smaller than arr2[right]:
// 	while (left>=0 && right<n){
// 		if (arr1[left]>arr2[right]){
// 			swap(arr1[left], arr2[right]);
// 			left--;
// 			right++;
// 		}
// 		else{
// 			break;
// 		}
// 	}
// 	sort(arr1.begin(), arr1.end());
// 	sort(arr2.begin(), arr2.end());
// }

#include <bits/stdc++.h>
vector<int> merge(vector<int>& arr1,vector<int>& arr2,int m,int n){
	vector<int> v;
	int cnt=0;
	int i=0;
	int j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]<arr2[j]) {
			v.push_back(arr1[i]);
            i++;
		}
		else if(arr1[i]==arr2[j]){
			v.push_back(arr1[i]);
			i++;
			//j++;
		}
		else if(arr1[i]>arr2[j]){
			v.push_back(arr2[j]);
			j++;
		}
	}
	while(i<arr1.size()) {
		v.push_back(arr1[i]);
		i++;
	}
	while(j<arr2.size()) {
		v.push_back(arr2[j]);
		j++;
	}
	return v;
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	vector<int> a1;
	for(int i=0;i<arr1.size();i++){
		if(arr1[i]!=0) a1.push_back(arr1[i]);
	}
	return merge(a1,arr2,m,n);
}
