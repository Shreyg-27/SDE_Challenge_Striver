#include<bits/stdc++.h>
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.size();
	int low = 0;
	int high = n-1;
	int x = high;
	int count = 0;
	while (low<high){
		if (str[low]==str[high]){
			low ++;
			high--;
		}
		else{
			count++;
			low=0;
			x--;
			high = x;
		}
	}
	return count;
	
}
