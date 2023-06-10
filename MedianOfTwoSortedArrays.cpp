#include<bits/stdc++.h>
double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int m = a.size();
	int n = b.size();
	// we need to take the min length array 
	if (m>n){
		return median(b,a);
	}
	int low = 0;
	int high = m; // posn of low length arr
	int median_pos = ((m+n)+1)/2;
	while (low<=high){
		int cut1 = (low+high)>>1;
		int cut2 = median_pos-cut1;

		int l1 = (cut1==0) ? INT_MIN : a[cut1-1];
		int l2 = (cut2==0) ? INT_MIN : b[cut2-1];
		int r1 = (cut1==m) ? INT_MAX : a[cut1];
		int r2 = (cut2==n) ? INT_MAX : b[cut2];

        // check for the valid condition 

		if (l1<=r2 && l2<=r1){
			if ((m+n)%2 != 0){
				return max(l1,l2);
			}
			else{
				return  (max(l1,l2)+min(r1,r2))/2.0;
			}
		}
		else if (l1>r2){
			high = cut1-1;
		}
		else{
			low = cut1 + 1;
		}

	}
	return 0.0;

}
